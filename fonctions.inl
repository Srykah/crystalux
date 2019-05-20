//
// Created by Thomas on 08/05/2019.
//

template <typename T>
T scal(sf::Vector2<T> v1, sf::Vector2<T> v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

template <typename T>
sf::Vector2<T> rightNorm(sf::Vector2<T> v) {
    return sf::Vector2<T>(-v.y, v.x);
}

template <typename T>
bool rightOf(sf::Vector2<T> s1, sf::Vector2<T> s2, sf::Vector2<T> p) {
    return scal(rightNorm(s2-s1), p-s1) >= 0.f;
}

template <typename T>
void centerOrigin(T& object) {
    object.setOrigin(object.getLocalBounds().left + object.getLocalBounds().width / 2.f, object.getLocalBounds().top + object.getLocalBounds().height / 2.f);
}