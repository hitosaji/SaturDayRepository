#include"Dxlib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    ChangeWindowMode(TRUE);         // ウィンドウモード
    SetGraphMode(640, 440, 32);
    DxLib_Init();           // DxLib初期化
    SetDrawScreen(DX_SCREEN_BACK);

    while (ProcessMessage() == 0)
    {
        ClearDrawScreen();

        DrawString(10, 10, "松本　優心です", GetColor(255, 255, 255));

        ScreenFlip();
    }
    DxLib_End();
    return 0;
}