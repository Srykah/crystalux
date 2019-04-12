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

class Grid : public sf::Drawable, public sf::Transformable {
public:
    explicit Grid(Context context, int level);
    void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates()) const override;

    sf::Vector2f getSize() const;

private:
    std::vector<Tile> mTiles;
    sf::VertexArray mGrid;
    std::map<std::pair<int, int>, int> mVertexMap;
    Context mContext;
};


#endif //CRYSTALUX_GRID_HPP
