//
// Created by Thomas on 06/04/2019.
//

#ifndef CRYSTALUX_TILE_HPP
#define CRYSTALUX_TILE_HPP

#include "Connexion.hpp"
#include "pugixml.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Vector2.hpp>
#include <array>
#include <vector>

class Tile : public sf::Drawable, public sf::Transformable {
public:
    Tile(); // empty tile
    Tile(std::array<Connexion::Color, 6> colors, bool movable);

    void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates()) const override;
    void setCoords(sf::Vector2i coords);
    sf::Vector2i getCoords() const;
    Connexion& getConnexion(unsigned int i);
    const Connexion& getConnexion(unsigned int i) const;
    bool contains(sf::Vector2f gridPos) const;
    bool empty() const;
    bool movable() const;

private:
    sf::Vector2i mCoords;
    std::array<Connexion, 6> mConnexions;
    bool mEmpty;
    bool mMovable;
    sf::CircleShape mBackground;
};

#endif //CRYSTALUX_TILE_HPP
