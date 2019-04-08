//
// Created by Thomas on 06/04/2019.
//

#include "Tile.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

const float halfSqrt3 = 0.86602540378443864676372317075294f;

Tile::Tile(pugi::xml_node node)
: mCoords(
    node.attribute("x").as_int(0),
    node.attribute("y").as_int(0)
), mEmpty(node.attribute("empty").as_bool(false))
, mMovable(node.attribute("movable").as_bool(!mEmpty))
, mBackground(50.f, 6) {
    mBackground.setOrigin(mBackground.getLocalBounds().width/2, mBackground.getLocalBounds().height/2);
    mBackground.rotate(30.f);
    if (mEmpty) {

    } else {
        if (mMovable) {

        } else {

        }
        for (char i(0); i < 6; i++) {
            auto attrName = std::string("co_") + std::to_string(i);
            mConnexions[i] = static_cast<Connexion>(node.attribute(attrName.c_str()).as_string(".")[0]);
        }
    }
}

void Tile::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(mBackground, states);
    for (const auto& crystal : mCrystals)
        target.draw(crystal, states);
}

void Tile::setCoords(sf::Vector2i coords) {
    mCoords = coords;

}

sf::Vector2i Tile::getCoords() const {
    return mCoords;
}
