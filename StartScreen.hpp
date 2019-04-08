//
// Created by Thomas on 06/04/2019.
//

#ifndef CRYSTALUX_STARTSCREEN_HPP
#define CRYSTALUX_STARTSCREEN_HPP

#include "GameMode.hpp"
#include "Button.hpp"
#include <SFML/Graphics/Text.hpp>

class StartScreen : public GameMode {
public:
    explicit StartScreen(Context context);

    void handleEvent(sf::Event event) override;
    void update(sf::Time delta) override;
    void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates()) const override;

private:
    sf::Text mText;
    Button mButton;
};


#endif //CRYSTALUX_STARTSCREEN_HPP
