#ifndef __SPRITE_NODE_H__
#define __SPRITE_NODE_H__

#include "SceneNode.h"

#include <SFML/Graphics/Sprite.hpp>


class SpriteNode : public SceneNode
{
public:
    explicit SpriteNode(const sf::Texture& texture);
    SpriteNode(const sf::Texture& texture, const sf::IntRect& textureRect);


private:
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;


private:
    sf::Sprite mSprite;
};

#endif // __SPRITE_NODE_H__
