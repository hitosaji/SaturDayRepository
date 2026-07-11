#include "DxLib.h"
#include"Game1.h"
#include"MoleManager1.h"
#include"Mole1.h"


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    ChangeWindowMode(TRUE);
    SetGraphMode(800, 600, 32);
    SetDrawScreen(DX_SCREEN_BACK);
    if (DxLib_Init() == -1) return -1;

    Game game;

    int prevTime = GetNowCount();

    int prevMouse = 0;

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
    {

        int nowTimer= GetNowCount();

        float dt = (nowTimer - prevTime) / 1000.0f;

        prevTime = nowTimer;

        int mx, my;

        GetMousePoint(&mx, &my);

        int mouse = GetMouseInput();

        bool click = false;

        if ((mouse & MOUSE_INPUT_LEFT) &&!(prevMouse & MOUSE_INPUT_LEFT))
        {
            click = true;
        }

            prevMouse = mouse;

        game.Update(dt, mx, my, click);

        ClearDrawScreen();

		game.Draw();

        ScreenFlip();
    }

    DxLib_End();

    return 0;
}