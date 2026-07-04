#include"Dxlib.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    ChangeWindowMode(TRUE);// ウィンドウモード
    SetGraphMode(640, 440, 32);
    DxLib_Init();           // DxLib初期化
    SetDrawScreen(DX_SCREEN_BACK);

    int favoritecharacter;

    favoritecharacter = LoadGraph("favorite.png");
    while (ProcessMessage() == 0)
    {
        ClearDrawScreen();

        DrawString(10, 10, "松本　優心です", GetColor(255, 255, 255));

        DrawString(50, 220, "私の推し、FGOの雑賀孫一です→", GetColor(255, 255, 255));

        DrawExtendGraph(320, 0, 640, 440, favoritecharacter, TRUE);

        ScreenFlip();
    }
    DxLib_End();
    return 0;
}