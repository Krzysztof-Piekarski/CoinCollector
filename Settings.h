#pragma once

class Settings
{
public:
	Settings() = default;
	~Settings() = default;

	float width();
	float height();
	
	bool isPressedUp();
	bool isPressedDown();
	bool isPressedRight();
	bool isPressedLeft();

	int score = 0;
	int goal = 70;
	float currentTime;

private:
	float widthInPixels{1200}, heightInPixels{675};
};