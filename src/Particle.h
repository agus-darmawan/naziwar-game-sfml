#ifndef __PARTICLE_H__
#define __PARTICLE_H__

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Time.hpp>

struct Particle
{
    enum Type {
        Propellant,
        Smoke,
        ParticleCount
    };

    sf::Vector2f position;
    sf::Color color;
    sf::Time lifetime;
};

#endif // __PARTICLE_H__
