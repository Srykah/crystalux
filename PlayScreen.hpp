//
// Created by Thomas on 06/04/2019.
//

#ifndef CRYSTALUX_PLAYSCREEN_HPP
#define CRYSTALUX_PLAYSCREEN_HPP

#include "GameMode.hpp"
#include "Grid.hpp"
#include "Button.hpp"

class PlayScreen : public GameMode {
public:
    PlayScreen(Context context, int i);

    void handleEvent(sf::Event event) override;
    void update(sf::Time delta) override;
    void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates()) const override;

private:
    Grid mGrid;
    Button mMenuButton;
    Button mNextLevelButton;
    Tile* mSelection;
    bool mGridValid;
    sf::Text mWinText;
};


#endif //CRYSTALUX_PLAYSCREEN_HPP
