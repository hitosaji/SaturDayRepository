#include "DxLib.h"
#include "MoleManager1.h"

//====================================
//初期化（モグラ数設定）
//====================================

void MoleManager::Init(int count)
{
	moles.resize(count);
}

//====================================
//更新（モグラの更新）
//====================================

void MoleManager::Update(float dt)
{
	//for (int i = 0; i < moles.size(); i++)
	for (auto& mole : moles)
	{
		mole.Update(dt);
	}
}
//====================================
//描画（モグラの描画）
//====================================

void MoleManager::Draw(int normalImg, int hitImg, int throughImg)
{
	for (auto& mole : moles)
	{
		mole.Draw(normalImg, hitImg,throughImg);
	}
}

//====================================
//クリック処理（1回のみ有効）
//====================================

bool MoleManager::HandClick(int mx, int my)
{
	for (auto& mole : moles)
	{
		if (mole.Ishit(mx, my));
		{
			return true;
		}
	}
	return false;
}

