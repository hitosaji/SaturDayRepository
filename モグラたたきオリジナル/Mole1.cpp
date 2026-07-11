#include "DxLib.h"
#include "Mole1.h"

Mole::Mole()
{
	x = 0;
	y = 0;
	timer = 0.0f;
	state = &g_HiddenState;
}

//=====================================
//更新
//=====================================
void Mole::Update(float dt)
{
	state->Update(*this, dt);
}

//=====================================
//描画
//=====================================
void Mole::Draw(int normalImg, int hitImage,int throughImg)
{
	state->Draw(*this, normalImg, hitImage,throughImg);
}

//=====================================
//ヒット
//=====================================
bool Mole::Ishit(int mx, int my)
{
	return state->OnClick(*this, mx, my);
}

//=====================================
//状態変化
//=====================================
void Mole::ChangeState(IMoleState* newState)
{
	timer = 0.0f;
	state = newState;
}