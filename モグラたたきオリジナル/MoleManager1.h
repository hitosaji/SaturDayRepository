#pragma once
#include<vector>
#include"Mole1.h"

class MoleManager
{
private:
	//モグラの数を保持
	std::vector<Mole> moles;
public:
	//モグラ生成
	void Init(int count);

	//モグラ更新
	void Update(float dt);

	//モグラ描画
	void Draw(int noemalImg, int hitImg, int throughImg);

	//全モグラクリア判定
	bool HandClick(int mx, int my);

};
