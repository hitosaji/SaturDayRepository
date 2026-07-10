#pragma once
#include"MoleState1.h"
class Mole
{
public:
	float x, y;
	float timer;
	IMoleState* state;

	Mole();

	void Update(float dt);
	void Draw(int normalImage, int hitImage, int throughImg);
	bool Ishit(int mx, int my);
	void ChangeState(IMoleState* newState);

};