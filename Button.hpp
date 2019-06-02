//
// Created by Thomas on 05/04/2019.
//

#ifndef CRYSTALUX_BUTTON_HPP
#define CRYSTALUX_BUTTON_HPP

#include "Context.hpp"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <functional>

class Button : public sf::Drawable, public sf::Transformable {
public:
    static constexpr float WIDTH = 80.f;
    static constexpr float HEIGHT = 80.f;
public:
    Button(const sf::String& text, std::function<void()> callback, Context context);

    void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates()) const override;

    bool contains(sf::Vector2f mousePos) const;
    void highlight(bool flag = true);
    void activate();

    sf::FloatRect getLocalBounds() const;

private:
    sf::RectangleShape mBackground;
    sf::Text mText;
    std::function<void()> mCallback;
};


#endif //CRYSTALUX_BUTTON_HPP
