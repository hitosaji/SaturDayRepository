#include "DxLib.h"
#include"Game1.h"
#include "MoleManager1.h"


Game::Game()
{
	hitImage = LoadGraph("image/magoiti hit.png");
	normalImage = LoadGraph("image/magoiti normal.png");
	throughImage = LoadGraph("image/magoiti smile.png");
	background = LoadGraph("image/background.png");

	moleManager.Init(4);
}

void Game::Update(float dt, int mx, int my, bool click)
{
	moleManager.Update(dt);
	if (click)
	{
		if (moleManager.HandClick(mx, my))
		{
			score += 5;
		}
	}
}

void Game::Draw()
{
	DrawGraph(0, 0, background, TRUE);
}