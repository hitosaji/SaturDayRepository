#pragma once
class Mole;
//状態インターフェース
class IMoleState
{
public:
	virtual void Update(Mole& mole, float dt) = 0;
	virtual void Draw(Mole& mole, int normalImg, int hitImg,int throwghImg) = 0;
	virtual bool OnClick(Mole& mole, int mx, int my) = 0;
};

//各状態
class HiddenState : public IMoleState
{
public:
	void Update(Mole& mole, float dt) override;
	void Draw(Mole& mole, int, int,int) override;
	bool OnClick(Mole& mole, int, int) override;
};
class VisibleState : public IMoleState
{
public:
	void Update(Mole& mole, float dt) override;
	void Draw(Mole& mole, int normalImg, int,int throughImg) override;
	bool OnClick(Mole& mole, int mx, int my) override;
};

class HitState : public IMoleState
{
public:
	void Update(Mole& mole, float dt) override;
	void Draw(Mole& mole, int, int hitImage,int) override;
	bool OnClick(Mole& mole, int mx, int my) override;
};

//共有インスタンス
extern HiddenState g_HiddenState;
extern VisibleState g_VisibleState;
extern HitState g_hitState;