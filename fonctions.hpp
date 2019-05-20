//
// Created by Thomas on 08/05/2019.
//

#ifndef CRYSTALUX_FONCTIONS_HPP
#define CRYSTALUX_FONCTIONS_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Shape.hpp>

template <typename T>
T scal(sf::Vector2<T> v1, sf::Vector2<T> v2);

template <typename T>
sf::Vector2<T> rightNorm(sf::Vector2<T> v);

template <typename T>
bool rightOf(sf::Vector2<T> segmentOrigin, sf::Vector2<T> segmentEnd, sf::Vector2<T> point);

bool contains(const sf::Shape& shape, sf::Vector2f point);

template <typename T>
void centerOrigin(T& object);

#include "fonctions.inl"

#endif //CRYSTALUX_FONCTIONS_HPP
