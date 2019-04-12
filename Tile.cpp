//
// Created by Thomas on 06/04/2019.
//

#include "Tile.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

const float sqrtOf3 = 1.73205080757f;

Tile::Tile(pugi::xml_node node)
: mCoords(
    node.attribute("x").as_int(0),
    node.attribute("y").as_int(0)
), mEmpty(node.attribute("empty").as_bool(false))
, mMovable(node.attribute("movable").as_bool(!mEmpty))
, mBackground(50.f, 6) {
    mBackground.setOrigin(50.f, 50.f);
    mBackground.rotate(30.f);
    if (mEmpty) {
        mBackground.setFillColor(sf::Color(70,130,180));
        mBackground.setOutlineThickness(-1);
        mBackground.setOutlineColor(sf::Color(100,149,237));
    } else {
        if (mMovable) {
            mBackground.setFillColor(sf::Color(255,222,173));
            mBackground.setOutlineThickness(-3);
            mBackground.setOutlineColor(sf::Color(210,180,140));
        } else {
            mBackground.setFillColor(sf::Color(188,143,143));
        }
        for (char i(0); i < 6; i++) {
            auto attrName = std::string("co_") + std::to_string(i);
            mConnexions[i] = static_cast<Connexion>(node.attribute(attrName.c_str()).as_string(".")[0]);
            if (mConnexions[i] != NONE) {
                mCrystals.emplace_back(sf::Vector2f(10.f, 30.f));
                mCrystals.back().setOrigin(5.f, sqrtOf3*0.5f*50.f);
                mCrystals.back().rotate(i*60.f);
                switch (mConnexions[i]) {
                    case RED:
                        mCrystals.back().setFillColor(sf::Color::Red);
                        break;
                    case GREEN:
                        mCrystals.back().setFillColor(sf::Color::Green);
                        break;
                    case BLUE:
                        mCrystals.back().setFillColor(sf::Color::Blue);
                        break;
                    case YELLOW:
                        mCrystals.back().setFillColor(sf::Color::Yellow);
                        break;
                    default:
                        break;
                }
            }
        }
    }
    setCoords(sf::Vector2i(
        node.attribute("x").as_int(),
        node.attribute("y").as_int()
    ));
}

void Tile::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= mTransform;
    target.draw(mBackground, states);
    for (const auto& crystal : mCrystals)
        target.draw(crystal, states);
}

void Tile::setCoords(sf::Vector2i coords) {
    mCoords = coords;
    sf::Transformable transformable;
    transformable.setPosition(
        coords.x*1.5f*50.f,
        (coords.y-0.5f*coords.x)*sqrtOf3*50.f
    );
    mTransform = transformable.getTransform();
}

sf::Vector2i Tile::getCoords() const {
    return mCoords;
}
