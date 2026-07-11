#include "DxLib.h"
#include"Game1.h"
#include "MoleManager1.h"


Game::Game()
{
	gameState = GameState::Title;
	score = 0;
	gameTimer = 30.0f;

	hitImg = LoadGraph("image/magoiti hit.png");
	normalImg = LoadGraph("image/magoiti normal.png");
	throughImg = LoadGraph("image/magoiti smile.png");
	background = LoadGraph("image/background.png");

	moleManager.Init(6);
}

void Game::Update(float dt, int mx, int my, bool click)
{
	switch (gameState)
	{
	case GameState::Title:


		if (click)
		{
			gameState = GameState::Playing;
			gameTimer = 3000.0f;
			score = 0;
		}
		break;

		case GameState::Playing:

			gameTimer -= dt;

			moleManager.Update(dt);
	
		if (click)
		{
			if (moleManager.HandClick(mx, my))
			{
				score += 5;
			}
			else
			{
				score -= 5;
			}
		}
	
			
		if (gameTimer <= 0)
		{
			gameState = GameState::Result;
		}
		break;
	
		case GameState::Result:
			if (click)
			{
				gameState = GameState::Title;
			}
			break;
	}
		
	
}

void Game::Draw()
{
	DrawGraph(0, 0, background, TRUE);

	switch (gameState)
	{
	case GameState::Title:

		DrawString(300, 250, "Game start", GetColor(255, 255, 255));

		break;

	case GameState::Playing:

		moleManager.Draw(normalImg, hitImg, throughImg);
		break;

	case GameState::Result:

		DrawString(300, 220, "Game Set", GetColor(255, 255, 255));

		break;
	}

		char str[64];
			sprintf_s(str, "Score:%03d", score);
				DrawString(10, 10, str, GetColor(255, 255, 255));
}