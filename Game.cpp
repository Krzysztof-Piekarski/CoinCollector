#include "Game.h"

Game::Game(Settings& t_set, sf::RenderWindow& t_window, sf::Event& t_event, float& t_bestTime)
    : set(t_set), window(t_window), event(t_event), bestTime(t_bestTime)
{
    round();
}

void Game::round()
{
    Burger burger(set);
    Player player(set, burger);
    Enemy enemy(player);
    Text text(set);
    std::vector<Coin*> coins;

    for (int i = 0; i < 8; ++i)
    {
        coins.push_back(new Coin(set, player));
    }

    while (!(set.score >= set.goal))
    {
        window.pollEvent(event);
        window.clear(sf::Color(255, 255, 255, 255));

        if (event.type == sf::Event::Closed)
        {
            window.close();
            break;
        }

        player.update();
        text.update();
        if (bestTime < 9998) text.string += "\nBest time: " + std::to_string(bestTime);
        text.text.setString(text.string);
        enemy.update();
        burger.update();
        for (auto& c : coins)
        {
            c->update();
            window.draw(c->sprite);
        }
        window.draw(burger.sprite);
        window.draw(player.sprite);
        window.draw(enemy.sprite);
        window.draw(text.text);

        window.display();
    }
    set.currentTime = text.textClock.getElapsedTime().asSeconds();
    if (set.currentTime < bestTime)
        bestTime = set.currentTime;
    set.score = 0;
    window.clear(sf::Color(255, 255, 255, 255));
    text.displayTime();
    window.draw(text.text);
    window.display();
    while (1)
    {
        if (text.textClock.getElapsedTime().asSeconds() > 2)
            break;
    }
}