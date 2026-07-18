#pragma once

//ピッチャーが投げる球の種類の最小値
const int PITCHING_MIN = 0;
//ピッチャーが投げる球の種類の最大値
const int PITCHING_MAX = 3;
//25%の確率でボールやアウトにする定数
const int PROBABILITY = 4;

//ストライク数のカウント
const int STRIKE_COUNT = 3;
//ボール数のカウント
const int BALL_COUNT = 4;
//アウト数のカウント
const int OUT_COUNT = 3;
//ヒットした時のカウント
const int HIT_COUNT = 4;

//投球の種類
enum PitchType
{
	Straight,
	Curve,
	Slider,
	Sinker
};

//投げる球の種類を選ぶ関数
void PitchingType(int pitching);
//ゲーム終了関数
void Result(int out);
//入力関数
int InputCheck(int min, int max);