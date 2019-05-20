//
// Created by Thomas on 05/04/2019.
//

#ifndef CRYSTALUX_APPLICATION_HPP
#define CRYSTALUX_APPLICATION_HPP

#include "GameMode.hpp"
#include "Tile.hpp"
#include "Context.hpp"
#include "ModeManager.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/System/Time.hpp>
#include <memory>

class Application {
public:
    Application();
    void run();

private:
    void handleEvents();
    void update(sf::Time delta);
    void render();
    Context getContext();

private:
    sf::RenderWindow mWindow;
    ModeManager mModeManager;
    sf::Font mFont;
};


#endif //CRYSTALUX_APPLICATION_HPP
