//
// Created by Thomas on 05/04/2019.
//

#include "MainMenu.hpp"
#include "PlayScreen.hpp"
#include "ModeManager.hpp"
#include "fonctions.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <sstream>

MainMenu::MainMenu(Context context)
: GameMode(context)
, mText("Menu ppal", context.font, 50) {
    for (int i = 0; i < mContext.levelCount; i++) {
        mButtons.emplace_back(std::to_string(i+1), [this, i](){
            mContext.modeManager.setMode(new PlayScreen(mContext, i+1));
        }, context);
        mButtons.back().setPosition(50.f+(Button::WIDTH+10.f)*(i%3), 100.f+(Button::HEIGHT+10.f)*(i/3));
    }
    centerOrigin(mText);
    mText.setPosition(180.f, 50.f);
}

void MainMenu::handleEvent(sf::Event event) {
    if (event.type == sf::Event::MouseMoved) {
        for (auto& button : mButtons) {
            if (button.contains(sf::Vector2f(sf::Mouse::getPosition(mContext.window))))
                button.highlight();
            else
                button.highlight(false);
        }
    } else if (event.type == sf::Event::MouseButtonPressed) {
        for (auto& button : mButtons) {
            if (button.contains(sf::Vector2f(sf::Mouse::getPosition(mContext.window))))
                button.activate();
        }
    }
}

void MainMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(mText, states);
    for (auto& button : mButtons)
        target.draw(button);
}
