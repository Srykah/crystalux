//
// Created by Thomas on 05/04/2019.
//

#include "MainMenu.hpp"
#include "PlayScreen.hpp"
#include "ModeManager.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <sstream>
#include <iostream>

class P {
public:
    explicit P(Context context)
    : mContext(context)
    , i(0) {}

    Button operator()() {
        std::stringstream ss;
        ss << i+1;
        Button button(std::to_string(i+1),
            std::bind(&ModeManager::setMode, &mContext.modeManager, new PlayScreen(mContext, i)),
            mContext);
        button.setPosition(50.f+(Button::WIDTH+10.f)*(i%3), 100.f+(Button::HEIGHT+10.f)*(i/3));
        i++;
        return button;
    }

private:
    Context mContext;
    int i;
};

MainMenu::MainMenu(Context context)
: GameMode(context)
, mText("Menu ppal", context.font, 50) {
    P p(mContext);
    std::generate_n(std::inserter(mButtons, mButtons.end()), context.levels.size(), p);
    mText.setOrigin(mText.getLocalBounds().width/2.f, mText.getLocalBounds().height/2.f);
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

void MainMenu::update(sf::Time delta) {

}

void MainMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(mText, states);
    for (auto& button : mButtons)
        target.draw(button);
}
