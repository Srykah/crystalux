//
// Created by Thomas on 07/04/2019.
//

#include "Grid.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

const float sqrtOf3 = 1.73205080757f;

Grid::Grid(Context context, int level)
: mTiles(context.levels.at(level))
, mContext(context) {}

void Grid::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    for (auto& tile : mTiles)
        target.draw(tile, states);
}

sf::Vector2f Grid::getSize() const {
    float minX(0), maxX(0), minZ(0), maxZ(0);
    for (auto& tile : mTiles) {
        sf::Vector2i coords = tile.getCoords();
        if (coords.x < minX)
            minX = coords.x;
        else if (coords.x > maxX)
            maxX = coords.x;
        if (coords.y-0.5f*coords.x < minZ)
            minZ = coords.y-0.5f*coords.x;
        else if (coords.y-0.5f*coords.x > maxZ)
            maxZ = coords.y-0.5f*coords.x;
    }
    return sf::Vector2f(
        50.f*(1.5f*(maxX-minX)+2),
        sqrtOf3*50.f*(maxZ-minZ+1)
    );
}
