//
// Created by Thomas on 06/04/2019.
//

#include "PlayScreen.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <iostream>

const float sqrtOf3 = 1.73205080757f;

PlayScreen::PlayScreen(Context context, int i)
: GameMode(context)
, mGrid(context, i) {
    sf::Vector2f size = mGrid.getSize();
    std::cout << size.x << ' ' << size.y << std::endl;
    float zoom = 1.f;
    if (size.x > 300.f)
        zoom = 300.f/size.x;
    if (size.y > 500.f && 500.f/size.y < zoom)
        zoom = 500.f/size.y;
    mGrid.setScale(zoom, zoom);
    mGrid.setPosition(
        180.f-(0.5f*size.x-50.f)*zoom,
        320.f-(0.5f*(size.y-sqrtOf3*50.f))*zoom
    );
}

void PlayScreen::handleEvent(sf::Event event) {

}

void PlayScreen::update(sf::Time delta) {

}

void PlayScreen::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(mGrid, states);
}
