#include "GameOverState.h"
#include "Utility.h"
#include "Player.h"
#include "ResourceHolder.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>


GameOverState::GameOverState(StateStack& stack, Context context)
    : State(stack, context)
    , mGameOverText()
    , mElapsedTime(sf::Time::Zero)
{
    sf::Font& font = context.fonts->get(Fonts::Main);
    sf::Vector2f windowSize(context.window->getSize());

    mGameOverText.setFont(font);
    if (context.player->getMissionStatus() == Player::MissionFailure)
        mGameOverText.setString("Gagal Bos");
    else
        mGameOverText.setString("Berhasil Bos");

    mGameOverText.setCharacterSize(70);
    centerOrigin(mGameOverText);
    mGameOverText.setPosition(0.5f * windowSize.x, 0.4f * windowSize.y);
}

void GameOverState::draw()
{
    sf::RenderWindow& window = *getContext().window;
    window.setView(window.getDefaultView());

    sf::RectangleShape backgroundShape;
    backgroundShape.setFillColor(sf::Color(0, 0, 0, 150));
    backgroundShape.setSize(window.getView().getSize());

    window.draw(backgroundShape);
    window.draw(mGameOverText);
}

bool GameOverState::update(sf::Time dt)
{
    mElapsedTime += dt;
    if (mElapsedTime > sf::seconds(3))
    {
        requestStateClear();
        requestStackPush(States::Menu);
    }
    return false;
}

bool GameOverState::handleEvent(const sf::Event&)
{
    return false;
}
