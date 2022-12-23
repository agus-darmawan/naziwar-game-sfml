#include "MenuState.h"
#include "Button.h"
#include "Utility.h"
#include "ResourceHolder.h"
#include "MusicPlayer.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>


MenuState::MenuState(StateStack& stack, Context context)
    : State(stack, context)
    , mGUIContainer()
{
    sf::Texture& texture = context.textures->get(Textures::TitleScreen);
    mBackgroundSprite.setTexture(texture);

    auto playButton = std::make_shared<GUI::Button>(context);
    playButton->setPosition(100, 300);
    playButton->setText("Main");
    playButton->setCallback([this] ()
    {
        requestStackPop();
        requestStackPush(States::Game);
    });

    auto settingsButton = std::make_shared<GUI::Button>(context);
    settingsButton->setPosition(100, 350);
    settingsButton->setText("Pengaturan");
    settingsButton->setCallback([this] ()
    {
        requestStackPush(States::Settings);
    });

    auto exitButton = std::make_shared<GUI::Button>(context);
    exitButton->setPosition(100, 400);
    exitButton->setText("Pulang");
    exitButton->setCallback([this] ()
    {
        requestStackPop();
    });

    mGUIContainer.pack(playButton);
    mGUIContainer.pack(settingsButton);
    mGUIContainer.pack(exitButton);

    context.music->play(Music::MenuTheme);
}

void MenuState::draw()
{
    sf::RenderWindow& window = *getContext().window;

    window.setView(window.getDefaultView());

    window.draw(mBackgroundSprite);
    window.draw(mGUIContainer);
}

bool MenuState::update(sf::Time)
{
    return true;
}

bool MenuState::handleEvent(const sf::Event& event)
{
    mGUIContainer.handleEvent(event);
    return false;
}
