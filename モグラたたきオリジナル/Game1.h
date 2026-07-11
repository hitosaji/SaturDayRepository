#pragma once
#include"MoleManager1.h"

enum class GameState
{
	Title,
	Playing,
	Result
};
class Game
{

private:
	MoleManager moleManager;

	GameState gameState;

	int score;
	int gameTimer;
public:
	Game();

	void Update(float dt, int mx, int my, bool click);

	void Draw();

	int hitImg;
	int normalImg;
	int throughImg;
	int background;

};