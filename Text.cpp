#include "Text.h"

Text::Text(Settings& tSet) : textSet(tSet)
{
	font.loadFromFile("VCR_OSD_MONO.ttf");
	text.setFont(font);
	text.setFillColor(sf::Color(255, 0, 0, 255));
	text.setPosition(15, 15);
	text.setCharacterSize(20);
}

void Text::update()
{
	string = "Time: " + std::to_string(textClock.getElapsedTime().asSeconds()) + "\nScore: " + std::to_string(textSet.score) + " / " + std::to_string(textSet.goal);
}

void Text::displayTime()
{
	textClock.restart();
	text.setPosition(120, (textSet.height() / 2)-50);
	text.setCharacterSize(80);
	string = "Your time: " + std::to_string(textSet.currentTime);
	text.setString(string);
}