#ifndef BLOOMEFFECT_H
#define BLOOMEFFECT_H

#include "PostEffect.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderTexture.hpp>

#include <array>

class BloomEffect : public PostEffect
{
public:
    BloomEffect();

    // PostEffect interface
    void apply(const sf::RenderTexture &input, sf::RenderTarget &output) override;

private:
    typedef std::array<sf::RenderTexture, 2> RenderTextureArray;

private:
    void prepareTextures(sf::Vector2u size);

    void filterBright(const sf::RenderTexture& input, sf::RenderTexture& output);
    void blurMultipass(RenderTextureArray& renderTextures);
    void blur(const sf::RenderTexture& input, sf::RenderTexture& output, sf::Vector2f offsetFactor);
    void downsample(const sf::RenderTexture& input, sf::RenderTexture& output);
    void add(const sf::RenderTexture& source, const sf::RenderTexture& bloom, sf::RenderTarget& target);

private:
    ShaderHolder mShaders;
    sf::RenderTexture mBrightnessTexture;
    RenderTextureArray mFirstPassTextures;
    RenderTextureArray mSecondPassTextures;
};

#endif // BLOOMEFFECT_H
