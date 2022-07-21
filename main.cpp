#include <SFML/Graphics.hpp>
#include "Settings.h"
#include "Game.h"

void newRound(Settings& t_set, sf::RenderWindow& t_window, sf::Event& t_event, float& t_bestTime)
{
    Game game(t_set, t_window, t_event, t_bestTime);
}

int main()
{
    Settings set;
    sf::RenderWindow window{ sf::VideoMode(set.width(), set.height()), "Coin Collector" };
    sf::Event event;
    window.setFramerateLimit(60);
    
    float bestTime = 9999;

    while(window.isOpen())
    {
        newRound(set, window, event, bestTime);
    }
    return 0;
}
