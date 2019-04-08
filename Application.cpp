//
// Created by Thomas on 05/04/2019.
//

#include "Application.hpp"
#include "StartScreen.hpp"
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <stdexcept>
#include <iostream>

const sf::Time TIME_PER_FRAME = sf::seconds(1.f/60.f);

Application::Application()
: mWindow(sf::VideoMode(360,640), "Crystalux", sf::Style::Close) {
    loadLevels();
    if (!mFont.loadFromFile("Media/Fonts/OpenSans.ttf"))
        throw std::runtime_error("Could not load font OpenSans");

    mModeManager.setMode(new StartScreen(getContext()));
}

void Application::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate;
    while (mWindow.isOpen()) {
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate >= TIME_PER_FRAME) {
            handleEvents();
            update(TIME_PER_FRAME);
            timeSinceLastUpdate -= TIME_PER_FRAME;
        }

        render();
    }
}

void Application::handleEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            mWindow.close();
        else
            mModeManager.handleEvent(event);
    }
}

void Application::update(sf::Time delta) {
    mModeManager.update(delta);
}

void Application::render() {
    mWindow.clear();
    mWindow.draw(mModeManager);
    mWindow.display();
}

void Application::loadLevels() {
    pugi::xml_document doc;
    if (!doc.load_file("Media/Levels/LevelMap.xml"))
        throw std::runtime_error("Couldn't load LevelMap.xml");
    for (pugi::xml_node& fileNode : doc.child("levelFiles").children("file")) {
        pugi::xml_document levelDoc;
        if (!levelDoc.load_file(fileNode.child_value()))
            throw std::runtime_error("Couldn't load LevelMap.xml");
        std::vector<Tile> level;
        for (auto tileNode : levelDoc.child("level").children("tile"))
            level.emplace_back(tileNode);
        mLevels.push_back(level);
    }
}

Context Application::getContext() {
    return {
        mWindow,
        mModeManager,
        mFont,
        mLevels
    };
}
