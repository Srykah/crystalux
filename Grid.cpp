//
// Created by Thomas on 07/04/2019.
//

#include "Grid.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

const sf::Vector2i offsets[6] = {
        sf::Vector2i(0,-1),
        sf::Vector2i(1,0),
        sf::Vector2i(1,1),
        sf::Vector2i(0,1),
        sf::Vector2i(-1,0),
        sf::Vector2i(-1,-1)
};

Grid::Grid()
: mCursor(50.f, 6)
, mShowCursor(false) {
    mCursor.setOrigin(50.f, 50.f);
    mCursor.setRotation(30.f);
    mCursor.setFillColor(sf::Color::Transparent);
    mCursor.setOutlineColor(sf::Color::Yellow);
    mCursor.setOutlineThickness(-3.f);
}

void Grid::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    for (auto& tile : mTiles)
        target.draw(tile, states);
    if (mShowCursor)
        target.draw(mCursor, states);
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

Tile* Grid::getTile(sf::Vector2f windowPos) {
    return const_cast<Tile*>(const_cast<const Grid&>(*this).getTile(windowPos));
}

const Tile* Grid::getTile(sf::Vector2f windowPos) const {
    sf::Vector2f localPoint = getInverseTransform().transformPoint(windowPos);
    for (const auto& tile : mTiles) {
        if (tile.contains(localPoint))
            return &tile;
    }

    return nullptr;
}

void Grid::selectTile(sf::Vector2i coords) {
    mShowCursor = true;
    mCursor.setPosition(
            coords.x*1.5f*50.f,
            (coords.y-0.5f*coords.x)*sqrtOf3*50.f
    );
}

void Grid::deselect() {
    mShowCursor = false;
}

void Grid::setTileCoords(Tile *tile, sf::Vector2i coords) {
    tile->setCoords(coords);

    for (int i = 0; i < 6; i++) { // dans l'ordre horaire, en partant d'en haut
        Tile* adjacentTile = getTileByCoords(coords + offsets[i]);
        if (adjacentTile) {
            if (tile->getConnexion(i).getColor() == adjacentTile->getConnexion((i+3)%6).getColor()) { // cristaux en face
                tile->getConnexion(i).activate();
                adjacentTile->getConnexion((i+3)%6).activate();
            } else {
                tile->getConnexion(i).deactivate();
                adjacentTile->getConnexion((i+3)%6).deactivate();
            }
        } else {
            if (tile->getConnexion(i).getColor() == Connexion::NONE)
                tile->getConnexion(i).activate();
            else
                tile->getConnexion(i).deactivate();
        }
    }
}

Tile *Grid::getTileByCoords(sf::Vector2i coords) {
    for (auto& tile : mTiles) {
        if (tile.getCoords() == coords)
            return &tile;
    }

    return nullptr;
}

void Grid::load(pugi::xml_node levelNode) {
    for (auto tileNode : levelNode.children("tile")) {
        bool empty = tileNode.attribute("empty").as_bool(false);
        if (empty) {
            mTiles.emplace_back(Tile());
        } else {
            std::array<Connexion::Color, 6> colors;
            for (char i(0); i < 6; i++) {
                auto attrName = std::string("co_") + std::to_string(i);
                colors[i] = static_cast<Connexion::Color>(tileNode.attribute(attrName.c_str()).as_string(".")[0]);
            }
            bool movable = tileNode.attribute("movable").as_bool(true);

            mTiles.emplace_back(colors, movable);
        }

        setTileCoords(&mTiles.back(), sf::Vector2i(
                tileNode.attribute("x").as_int(),
                tileNode.attribute("y").as_int()
        ));
    }
}

bool Grid::isValid() const {
    for (const auto& tile : mTiles) {
        for (int i = 0; i < 6; i++) {
            if (!tile.getConnexion(i).isActive())
                return false;
        }
    }

    return true;
}
