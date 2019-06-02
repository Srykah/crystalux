//
// Created by Thomas on 07/04/2019.
//

#include "ModeManager.hpp"
#include "GameMode.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

ModeManager::ModeManager(GameMode *mode)
: mMode(mode)
, mNeedUpdate(false)
, mNextMode(nullptr) {

}

void ModeManager::setMode(GameMode *mode) {
    mNextMode = mode;
    mNeedUpdate = true;
}

void ModeManager::handleEvent(sf::Event event) {
    if (mMode)
        mMode->handleEvent(event);
}

void ModeManager::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (mMode)
        target.draw(*mMode, states);
}

void ModeManager::update() {
    if (mNeedUpdate) {
        mMode.reset(mNextMode);
        mNeedUpdate = false;
    }
}
