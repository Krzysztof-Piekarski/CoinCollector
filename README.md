Game/SFML/C++

Required libraries: SFML (sudo apt-get install libsfml-dev)

To compile (on linux) type in terminal: 
g++ main.cpp Player.cpp Settings.cpp Enemy.cpp  Burger.cpp Coin.cpp Text.cpp Game.cpp -lsfml-graphics -lsfml-window -lsfml-system

The goal of the game is to collect 70 coins in the shortest time. The hero is controlled by using arrows. The burger increases his speed. He can pass between the edges of the window. However, watch out for the ghost!
