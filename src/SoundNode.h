#ifndef SOUNDNODE_H
#define SOUNDNODE_H

#include "SceneNode.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"

class SoundPlayer;

class SoundNode : public SceneNode
{
public:
    explicit SoundNode(SoundPlayer& player);
    void playSound(SoundEffect::ID sound, sf::Vector2f position);

    // SceneNode interface
public:
    unsigned int getCategory() const override;

private:
    SoundPlayer& mSounds;
};

#endif // SOUNDNODE_H
