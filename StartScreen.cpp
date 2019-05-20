//
// Created by Thomas on 06/04/2019.
//

#include "StartScreen.hpp"
#include "MainMenu.hpp"
#include "ModeManager.hpp"
#include "fonctions.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

StartScreen::StartScreen(Context context)
: GameMode(context)
, mText("Crystalux", context.font, 70)
, mButton('>', [this, context](){
    context.modeManager.setMode(new MainMenu(context));
}, context) {
    centerOrigin(mText);
    mText.setPosition(180.f, 180.f);
    mButton.setOrigin(mButton.getLocalBounds().width/2.f, mButton.getLocalBounds().height/2.f);
    mButton.setPosition(180.f, 460.f);
}

void StartScreen::handleEvent(sf::Event event) {
    if (event.type == sf::Event::MouseMoved) {
        if (mButton.contains(sf::Vector2f(sf::Mouse::getPosition(mContext.window))))
            mButton.highlight();
        else
            mButton.highlight(false);
    } else if (event.type == sf::Event::MouseButtonPressed) {
        if (mButton.contains(sf::Vector2f(sf::Mouse::getPosition(mContext.window))))
            mButton.activate();
    }
}

void StartScreen::update(sf::Time delta) {

}

void StartScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(mText, states);
    target.draw(mButton, states);
}
