//
// Created by Thomas on 06/04/2019.
//

#ifndef CRYSTALUX_CONNEXION_HPP
#define CRYSTALUX_CONNEXION_HPP

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

const float sqrtOf3 = 1.73205080757f;

class Connexion : public sf::Drawable, public sf::Transformable {
public:
    enum Color {
        NONE = '.',
        RED = 'r',
        GREEN = 'g',
        BLUE = 'b',
        YELLOW = 'y'
    };

public:
    Connexion();
    Connexion(Color color, int number);

    void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates()) const override;
    void activate();
    void deactivate();
    bool isActive() const;
    Color getColor() const;

private:
    Color mColor;
    sf::RectangleShape mCrystal;
    bool mActive;
};

#endif //CRYSTALUX_CONNEXION_HPP
