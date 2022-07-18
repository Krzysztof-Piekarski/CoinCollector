#pragma once
#include <SFML/Graphics.hpp>
#include "Settings.h"
#include "Player.h"
#include "Burger.h"
#include "Enemy.h"
#include "Coin.h"
#include "Text.h"

class Game
{
public:
	Game(Settings& t_set, sf::RenderWindow& t_window, sf::Event& t_event, float& bestTime);
	~Game() = default;
	void round();

private:
	Settings& set;
	sf::RenderWindow& window;
	sf::Event& event;
	float& bestTime;
};

