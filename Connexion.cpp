//
// Created by Thomas on 20/05/2019.
//

#include "Connexion.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

Connexion::Connexion()
: mColor(NONE)
, mActive(false) {

}

Connexion::Connexion(Connexion::Color color, int number)
: mColor(color)
, mCrystal(sf::Vector2f(10.f, 30.f))
, mActive(false) {
    setOrigin(5.f, sqrtOf3*0.5f*50.f);
    setPosition(50.f, 50.f);
    rotate(number*60.f-30.f);
    if (mColor == Connexion::NONE)
        mCrystal.setFillColor(sf::Color::Transparent);
    else
        deactivate();
}

void Connexion::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(mCrystal, states);
}

void Connexion::activate() {
    mActive = true;
    switch (mColor) {
        case RED:
            mCrystal.setFillColor(sf::Color::Red);
            break;
        case GREEN:
            mCrystal.setFillColor(sf::Color::Green);
            break;
        case BLUE:
            mCrystal.setFillColor(sf::Color::Blue);
            break;
        case YELLOW:
            mCrystal.setFillColor(sf::Color::Yellow);
            break;
        default:
            break;
    }
}

void Connexion::deactivate() {
    mActive = false;
    switch (mColor) {
        case RED:
            mCrystal.setFillColor(sf::Color(128,0,0));
            break;
        case GREEN:
            mCrystal.setFillColor(sf::Color(0,128,0));
            break;
        case BLUE:
            mCrystal.setFillColor(sf::Color(0,0,128));
            break;
        case YELLOW:
            mCrystal.setFillColor(sf::Color(128,128,0));
            break;
        default:
            break;
    }
}

bool Connexion::isActive() const {
    return mActive;
}

Connexion::Color Connexion::getColor() const {
    return mColor;
}
