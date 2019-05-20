//
// Created by Thomas on 06/04/2019.
//

#include "Tile.hpp"
#include "fonctions.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

Tile::Tile()
: mBackground(50.f, 6)
, mEmpty(true)
, mMovable(true) {
    setOrigin(50.f, 50.f);
    rotate(30.f);
    mBackground.setFillColor(sf::Color(70,130,180));
    mBackground.setOutlineThickness(-1);
    mBackground.setOutlineColor(sf::Color(100,149,237));
}

Tile::Tile(std::array<Connexion::Color, 6> colors, bool movable)
: mBackground(50.f, 6)
, mEmpty(false)
, mMovable(movable) {
    setOrigin(50.f, 50.f);
    rotate(30.f);

    for (char i(0); i < 6; i++)
        mConnexions[i] = Connexion(colors[i], i);

    if (mMovable) {
        mBackground.setFillColor(sf::Color(255,222,173));
        mBackground.setOutlineThickness(-3);
        mBackground.setOutlineColor(sf::Color(210,180,140));
    } else {
        mBackground.setFillColor(sf::Color(188,143,143));
    }
}
void Tile::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(mBackground, states);
    for (const auto& connexion : mConnexions)
        target.draw(connexion, states);
}


void Tile::setCoords(sf::Vector2i coords) {
    mCoords = coords;
    setPosition(
            mCoords.x*1.5f*50.f,
            (mCoords.y-0.5f*mCoords.x)*sqrtOf3*50.f
    );
}

sf::Vector2i Tile::getCoords() const {
    return mCoords;
}

bool Tile::contains(sf::Vector2f gridPos) const{
    return ::contains(mBackground, getInverseTransform().transformPoint(gridPos));
}

bool Tile::empty() const {
    return mEmpty;
}

bool Tile::movable() const {
    return mMovable;
}

Connexion &Tile::getConnexion(unsigned int i) {
    return mConnexions[i];
}

const Connexion &Tile::getConnexion(unsigned int i) const {
    return mConnexions[i];
}