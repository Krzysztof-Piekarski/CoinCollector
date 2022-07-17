#include <SFML/Graphics.hpp>
#include "Settings.h"
#include "Player.h"
#include "Burger.h"
#include "Enemy.h"
#include "Coin.h"
#include "Text.h"

float bestTime = 9999;
bool gameOver = false;

int main()
{
    Settings set;
    sf::RenderWindow window{ sf::VideoMode(set.width(), set.height()), "Coin Collector" };
    sf::Event event;
    window.setFramerateLimit(60);

    while(!gameOver)
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
            window.clear(sf::Color(255, 255, 255, 255));
            window.pollEvent(event);

            if (event.type == sf::Event::Closed)
            {
                window.close();
                gameOver = true;
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
    return 0;
}
