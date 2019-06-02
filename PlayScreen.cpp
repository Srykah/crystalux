//
// Created by Thomas on 06/04/2019.
//

#include "PlayScreen.hpp"
#include "MainMenu.hpp"
#include "ModeManager.hpp"
#include "fonctions.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

PlayScreen::PlayScreen(Context context, int i)
: GameMode(context)
, mGrid()
, mMenuButton('<', [this]() {
    mContext.modeManager.setMode(new MainMenu(mContext));
}, context)
, mRestartButton(L"×", [this, i]() {
    mContext.modeManager.setMode(new PlayScreen(mContext, i));
}, context)
, mNextLevelButton('>', [this, i]() {
    if (i == mContext.levelCount)
        mContext.modeManager.setMode(new MainMenu(mContext)); // à changer par l'écran des crédits
    else
        mContext.modeManager.setMode(new PlayScreen(mContext, i+1));
}, context)
, mSelection(nullptr)
, mGridValid(false)
, mLevelText("Niveau " + std::to_string(i), context.font, 30)
, mWinText(L"Vous avez gagné !", context.font, 30) {
    auto str = "Media/Levels/Level" + std::to_string(i) + ".xml";
    pugi::xml_document doc;
    if (!doc.load_file(str.c_str()))
        throw std::runtime_error("Couldn't load " + str);
    mGrid.load(doc.child("level"));

    sf::Vector2f size = mGrid.getSize();
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

    centerOrigin(mLevelText);
    mLevelText.setPosition(180.f, Button::HEIGHT / 2.f);

    centerOrigin(mWinText);
    mWinText.setPosition(180.f, 600.f - Button::HEIGHT);

    centerOrigin(mNextLevelButton);
    mNextLevelButton.setPosition(180.f, 620.f - Button::HEIGHT / 2.f);

    mRestartButton.setPosition(360.f - Button::WIDTH, 0.f);
}

void PlayScreen::handleEvent(sf::Event event) {
    sf::Vector2f mousePos(sf::Mouse::getPosition(mContext.window));

    if (event.type == sf::Event::MouseMoved) {
        if (mMenuButton.contains(mousePos))
            mMenuButton.highlight();
        else
            mMenuButton.highlight(false);

        if (mRestartButton.contains(mousePos))
            mRestartButton.highlight();
        else
            mRestartButton.highlight(false);

        if (mGridValid) {
            if (mNextLevelButton.contains(mousePos))
                mNextLevelButton.highlight();
            else
                mNextLevelButton.highlight(false);
        }
    } else if (event.type == sf::Event::MouseButtonPressed) {
        if (mMenuButton.contains(mousePos))
            mMenuButton.activate();
        else if (mRestartButton.contains(mousePos))
            mRestartButton.activate();

        if (!mGridValid) {
            Tile* tile(mGrid.getTile(mousePos));
            if (tile) {
                if (!mSelection) {
                    if (!tile->empty() && tile->movable()) {
                        mSelection = tile;
                        mGrid.selectTile(mSelection->getCoords());
                    }
                } else {
                    if (tile == mSelection) {
                        mGrid.deselect();
                        mSelection = nullptr;
                    } else if (tile->movable()) {
                        mGrid.deselect();
                        sf::Vector2i coords(mSelection->getCoords());
                        mGrid.setTileCoords(mSelection, tile->getCoords());
                        mGrid.setTileCoords(tile, coords);
                        mSelection = nullptr;

                        if (mGrid.isValid())
                            mGridValid = true;
                    }
                }
            }
        } else if (mNextLevelButton.contains(mousePos)) {
            mNextLevelButton.activate();
        }
    }
}

void PlayScreen::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(mGrid, states);
    target.draw(mMenuButton, states);
    target.draw(mRestartButton, states);
    target.draw(mLevelText, states);
    if (mGridValid) {
        target.draw(mNextLevelButton, states);
        target.draw(mWinText, states);
    }
}
