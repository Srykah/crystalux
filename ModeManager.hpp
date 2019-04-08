//
// Created by Thomas on 07/04/2019.
//

#ifndef CRYSTALUX_MODEMANAGER_HPP
#define CRYSTALUX_MODEMANAGER_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Time.hpp>
#include <memory>

class GameMode;

class ModeManager : public sf::Drawable {
public:
    explicit ModeManager(GameMode* mode = nullptr);
    void setMode(GameMode *mode);
    void handleEvent(sf::Event event);
    void update(sf::Time delta);
    void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates()) const override;

private:
    std::unique_ptr<GameMode> mMode;
    GameMode* mNextMode;
    bool mNeedUpdate;
};


#endif //CRYSTALUX_MODEMANAGER_HPP
