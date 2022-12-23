#ifndef __EMITTERNODE_H__
#define __EMITTERNODE_H__

#include "Particle.h"
#include "SceneNode.h"

class ParticleNode;

class EmitterNode : public SceneNode
{
public:
    explicit EmitterNode(Particle::Type type);

    // SceneNode interface
private:
    void updateCurrent(sf::Time dt, CommandQueue &commands) override;
    void emitParticles(sf::Time dt);

private:
    sf::Time mAccumulatedTime;
    Particle::Type mType;
    ParticleNode* mParticleSystem;
};

#endif // __EMITTERNODE_H__
