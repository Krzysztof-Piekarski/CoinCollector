# CoinCollector
Game/SFML/C++

Required libraries:
SFML

To compile (on linux) type in terminal:
g++ main.cpp Player.cpp Burger.cpp Enemy.cpp Settings.cpp Coin.cpp Text.cpp  -lsfml-graphics -lsfml-window -lsfml-system

The goal of the game is to collect 70 coins in the shortest time possible.
The hero is controlled by using arrows.
The burger increases its speed.
It can pass between the edges of the window.
However, watch out for the ghost!
