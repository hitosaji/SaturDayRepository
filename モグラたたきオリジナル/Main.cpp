#include "DxLib.h"
#include"Game1.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    ChangeWindowMode(TRUE);
    DxLib_Init();
    SetGraphMode(800, 600, 32);
    SetDrawScreen(DX_SCREEN_BACK);
    if (DxLib_Init() == -1) return -1;

    Game game;

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {

        ClearDrawScreen();

		game.Draw();

        ScreenFlip();
    }

    DxLib_End();

    return 0;
}