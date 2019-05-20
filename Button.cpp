//
// Created by Thomas on 05/04/2019.
//

#include "Button.hpp"
#include "fonctions.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

Button::Button(const sf::String& text, std::function<void()> callback, Context context)
: mBackground(sf::Vector2f(Button::WIDTH, Button::HEIGHT))
, mText(text, context.font, 50)
, mCallback(std::move(callback)) {
    mBackground.setOutlineThickness(-3.f);
    centerOrigin(mText);
    mText.setPosition(Button::WIDTH/2, Button::HEIGHT/2);
    highlight(false);
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(mBackground, states);
    target.draw(mText, states);
}

bool Button::contains(sf::Vector2f mousePos) const {
    return getTransform().transformRect(mBackground.getLocalBounds()).contains(mousePos);
}

void Button::highlight(bool flag) {
    if (flag) {
        mBackground.setFillColor(sf::Color(157, 192, 222));
        mBackground.setOutlineColor(sf::Color(199, 217, 236));
        mText.setFillColor(sf::Color(199, 217, 236));
    } else {
        mBackground.setFillColor(sf::Color(102, 153, 204));
        mBackground.setOutlineColor(sf::Color(157, 192, 222));
        mText.setFillColor(sf::Color(157, 192, 222));
    }
}

void Button::activate() {
    mCallback();
}

sf::FloatRect Button::getLocalBounds() const {
    return mBackground.getLocalBounds();
}

sf::FloatRect Button::getGlobalBounds() const {
    return getTransform().transformRect(getLocalBounds());
}
