#ifndef __UTILITY_H__
#define __UTILITY_H__

#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Vector2.hpp>

#include <sstream>
#include "Animation.h"

namespace sf
{
    class Sprite;
    class Text;
}

// Since std::to_string doesn't work on MinGW we have to implement
// our own to support all platforms.
template <typename T>
std::string	toString(const T& value);

// Convert enumerators to strings
std::string	toString(sf::Keyboard::Key key);

// Call setOrigin() with the center of the object
void centerOrigin(sf::Sprite& sprite);
void centerOrigin(sf::Text& text);
void centerOrigin(Animation& animation);

// Degree/radian conversion
float toDegree(float radian);
float toRadian(float degree);

// Random number generation
int randomInt(int exclusiveMax);

// Vector operations
float length(sf::Vector2f vector);
sf::Vector2f unitVector(sf::Vector2f vector);

#include "Utility.inl"
#endif // __UTILITY_H__
