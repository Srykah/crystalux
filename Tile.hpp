//
// Created by Thomas on 06/04/2019.
//

#ifndef CRYSTALUX_TILE_HPP
#define CRYSTALUX_TILE_HPP

#include "Connexions.hpp"
#include "pugixml.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Vector2.hpp>
#include <array>
#include <vector>

class Tile : public sf::Drawable {
public:
    explicit Tile(pugi::xml_node node);

    void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates()) const override;

    void setCoords(sf::Vector2i coords);
    sf::Vector2i getCoords() const;

private:
    sf::Vector2i mCoords;
    std::array<Connexion, 6> mConnexions;
    bool mEmpty;
    bool mMovable;
    sf::CircleShape mBackground;
    std::vector<sf::RectangleShape> mCrystals;
};

#endif //CRYSTALUX_TILE_HPP
