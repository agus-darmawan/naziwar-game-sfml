#ifndef __PICKUP_H__
#define __PICKUP_H__

#include "Entity.h"
#include "Command.h"
#include "ResourceIdentifiers.h"

#include <SFML/Graphics/Sprite.hpp>


class Aircraft;

class Pickup : public Entity
{
public:
    enum Type
    {
        HealthRefill,
        MissileRefill,
        FireSpread,
        FireRate,
        TypeCount
    };


public:
    Pickup(Type type, const TextureHolder& textures);

    virtual unsigned int getCategory() const;
    virtual sf::FloatRect getBoundingRect() const;

    void apply(Aircraft& player) const;


protected:
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;


private:
    Type mType;
    sf::Sprite mSprite;
};

#endif // __PICKUP_H__
