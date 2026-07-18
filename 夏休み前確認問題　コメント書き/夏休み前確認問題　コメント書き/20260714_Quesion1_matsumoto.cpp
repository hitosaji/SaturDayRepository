#include <iostream>
#include <cstdlib>
#include <ctime>
#include "20260714_QuesionHeader_matsumoto.h"
using namespace std;


//====================================
// メイン
//====================================
int main()
{
    //変数
    int player;
    int cpu;
    int probability;
    //変数の初期化
    int strike = 0;
    int ball = 0;
    int out = 0;
    int hit = 0;

    //ランダム関数の宣言
    srand((unsigned int)time(nullptr));

    cout << "野球盤ゲームスタートです" << endl;
    cout << "プレイヤーはピッチャーとなり、この回を守り切ってください" << endl;

    //ゲームループ
    do
    {
        cout << endl;
        cout << "投げる球を選んでください" << endl;
        cout << "0:ストレート" << endl;
        cout << "1:カーブ" << endl;
        cout << "2:スライダー" << endl;
        cout << "3:シンカー" << endl;

        //入力関数
        player = InputCheck(PITCHING_MIN, PITCHING_MAX);
        //選択
        PitchingType(player);
        //CPUの選択
        cpu = rand() % PROBABILITY;
        //25%の確率の宣言
        probability = rand() % PROBABILITY;

        //プレイヤーとCPUの選択された数字が違った場合の処理
        if (player != cpu)
        {
            //25％の確率でボールにする
            if (probability == 0)
            {
                cout << "ボール！" << endl;
                ball++;
            }
            else
            {
                cout << "ストライク！！" << endl;
                strike++;
            }
        }
        else
        {
            strike = 0;
            ball = 0;

            //25％の確率でアウトにする
            if (probability == 1)
            {
                cout << "OUT!!" << endl;
                out++;
            }
            else
            {
                cout << "HIT!!" << endl;
                hit++;
            }
        }

        //ストライクとフォアボールのカウントが規定値を超えた場合の処理
        if (strike >= STRIKE_COUNT || ball >= BALL_COUNT)
        {
            //3回ストライクをしたらアウトになる
            if (strike >= STRIKE_COUNT)
            {
                cout << "三振アウト！" << endl;
                out++;
            }
            //4回ボールしたらHitが増える
            else
            {
                cout << "フォアボール！" << endl;
                hit++;
            }

            //カウントの初期化
            strike = 0;
            ball = 0;
        }

        cout << endl;
        cout << "B : " << ball << endl;
        cout << "S : " << strike << endl;
        cout << "O : " << out << endl;
        cout << "Runner : " << hit << endl;
        //ループの終了
    } while (out < OUT_COUNT && hit < HIT_COUNT);

    //終了関数
    Result(out);

    return 0;
}