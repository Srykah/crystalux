//
// Created by Thomas on 05/04/2019.
//

#ifndef CRYSTALUX_GAMEMODE_HPP
#define CRYSTALUX_GAMEMODE_HPP

#include "Context.hpp"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>

class GameMode : public sf::Drawable {
public:
    explicit GameMode(Context context);

    virtual void handleEvent(sf::Event event) = 0;
    virtual void update(sf::Time delta) = 0;

protected:
    Context mContext;
};


#endif //CRYSTALUX_GAMEMODE_HPP
