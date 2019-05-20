//
// Created by Thomas on 08/05/2019.
//

#include "fonctions.hpp"

bool contains(const sf::Shape& shape, sf::Vector2f point) {
    for (int i = 0; i < shape.getPointCount()-1; i++) {
        if (!rightOf(shape.getPoint(i), shape.getPoint(i+1), point))
            return false;
    }

    return rightOf(shape.getPoint(shape.getPointCount()-1), shape.getPoint(0), point);
}
