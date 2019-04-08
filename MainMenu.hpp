//
// Created by Thomas on 05/04/2019.
//

#ifndef CRYSTALUX_MAINMENU_HPP
#define CRYSTALUX_MAINMENU_HPP

#include "GameMode.hpp"
#include "Button.hpp"
#include <vector>

class MainMenu : public GameMode {
public:
    explicit MainMenu(Context context);

    void handleEvent(sf::Event event) override;
    void update(sf::Time delta) override;
    void draw(sf::RenderTarget &target, sf::RenderStates states = sf::RenderStates()) const override;

private:
    sf::Text mText;
    std::vector<Button> mButtons;
};


#endif //CRYSTALUX_MAINMENU_HPP
