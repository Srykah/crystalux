//
// Created by Thomas on 05/04/2019.
//

#ifndef CRYSTALUX_CONTEXT_HPP
#define CRYSTALUX_CONTEXT_HPP

#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/Window.hpp>
#include <memory>

class ModeManager;

struct Context {
    const sf::Window& window;
    ModeManager& modeManager;
    const sf::Font& font;
    int levelCount;
};

#endif //CRYSTALUX_CONTEXT_HPP
