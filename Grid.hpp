//
// Created by Thomas on 07/04/2019.
//

#ifndef CRYSTALUX_GRID_HPP
#define CRYSTALUX_GRID_HPP

#include "Tile.hpp"
#include "Context.hpp"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Time.hpp>

class Grid : public sf::Drawable, public sf::Transformable {
public:
    Grid();

    void load(pugi::xml_node levelNode);

    void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates()) const override;

    sf::Vector2f getSize() const;
    Tile* getTile(sf::Vector2f windowPos);
    const Tile* getTile(sf::Vector2f windowPos) const;

    void selectTile(sf::Vector2i coords);
    void deselect();
    void setTileCoords(Tile* tile, sf::Vector2i coords);

    bool isValid() const;

private:
    Tile* getTileByCoords(sf::Vector2i coords);

private:
    std::vector<Tile> mTiles;
    sf::CircleShape mCursor;
    bool mShowCursor;
};


#endif //CRYSTALUX_GRID_HPP
