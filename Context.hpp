//
// Created by Thomas on 05/04/2019.
//

#ifndef CRYSTALUX_CONTEXT_HPP
#define CRYSTALUX_CONTEXT_HPP

#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/Window.hpp>
#include <memory>

class ModeManager;
class Tile;

struct Context {
    const sf::Window& window;
    ModeManager& modeManager;
    const sf::Font& font;
    const std::vector<std::vector<Tile>>& levels;
};

#endif //CRYSTALUX_CONTEXT_HPP
