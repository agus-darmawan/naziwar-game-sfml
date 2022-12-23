#ifndef __RESOURCE_IDENTIFIERS_H__
#define __RESOURCE_IDENTIFIERS_H__

// Forward declaration of SFML classes
namespace sf
{
class Texture;
class Font;
class Shader;
class SoundBuffer;
}

namespace Textures
{
enum ID
{
    Entities,
    Jungle,
    TitleScreen,
    Buttons,
    Explosion,
    Particle,
    FinishLine
};
}

namespace Fonts
{
enum ID
{
    Main,
};
}

namespace Shaders {
    enum ID {
        BrightnessPass,
        DownSamplePass,
        GuassianBlurPass,
        AddPass
    };
}

namespace Music {
enum ID {
    MenuTheme,
    MissionTheme
};
}

namespace SoundEffect {
enum ID {
    AlliedGunfire,
    EnemyGunfire,
    Explosion1,
    Explosion2,
    LaunchMissile,
    CollectPickup,
    Button
};
}

// Forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::ID>	FontHolder;
typedef ResourceHolder<sf::Shader, Shaders::ID> ShaderHolder;
typedef ResourceHolder<sf::SoundBuffer, SoundEffect::ID> SoundBufferHolder;

#endif // __RESOURCE_IDENTIFIERS_H__
