#ifndef __POSTEFFECT_H__
#define __POSTEFFECT_H__

#include <SFML/System/NonCopyable.hpp>

namespace sf {
class RenderTexture;
class RenderTarget;
class Shader;
}

class PostEffect : sf::NonCopyable
{
public:
    virtual ~PostEffect();
    virtual void apply(const sf::RenderTexture& input, sf::RenderTarget& output) = 0;

    static bool isSupported();

protected:
    static void applyShader(const sf::Shader& shader, sf::RenderTarget& output);
};

#endif // __POSTEFFECT_H__
