//
// Created by Thomas on 05/04/2019.
//

#include "Application.hpp"
#include "StartScreen.hpp"
#include <SFML/System/Sleep.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <stdexcept>

const sf::Time TIME_PER_FRAME = sf::seconds(1.f/60.f);

Application::Application()
: mWindow(sf::VideoMode(360,640), "Crystalux", sf::Style::Close) {
    if (!mFont.loadFromFile("Media/Fonts/OpenSans.ttf"))
        throw std::runtime_error("Could not load font Open Sans");

    mModeManager.setMode(new StartScreen(getContext()));
}

void Application::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate;
    while (mWindow.isOpen()) {
        timeSinceLastUpdate += clock.restart();
        for (; timeSinceLastUpdate >= TIME_PER_FRAME; timeSinceLastUpdate -= TIME_PER_FRAME)
            handleEvents();
        mModeManager.update();
        render();
        sf::sleep(TIME_PER_FRAME - timeSinceLastUpdate);
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

void Application::render() {
    mWindow.clear();
    mWindow.draw(mModeManager);
    mWindow.display();
}

Context Application::getContext() {
    return {
        mWindow,
        mModeManager,
        mFont,
        15
    };
}
