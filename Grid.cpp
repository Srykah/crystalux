//
// Created by Thomas on 07/04/2019.
//

#include "Grid.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

Grid::Grid(Context context, int level)
: mTiles(context.levels.at(level))
, mContext(context) {}

void Grid::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    for (auto& tile : mTiles)
        target.draw(mGrid, states);
}
