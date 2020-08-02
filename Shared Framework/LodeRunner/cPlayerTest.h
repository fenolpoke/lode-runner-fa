#pragma once

#include "cSprite.h"
#include "cAnimControl.h"

class cPlayerTest
{
public:
	//ambil dr cPlayer.h
	cAnimControl *animControl;
	std::vector<cSprite*> *playerSheet;
	float x, y;
	int width, height;
	bool keys[255];



	virtual void Render();
	virtual void Init();
	virtual void Update(float tpf = 0.0333);
	virtual void ReadKeyboard(unsigned char key, int x, int y, bool press);
	virtual void ReadSpecialKeyboard(unsigned char key, int x, int y, bool press);
	virtual void ReadMouse(int button, int state, int x, int y);

	cPlayerTest(std::vector<cSprite*> *playerSheet, float x, float y, int width, int height)
		:playerSheet(playerSheet), x(x), y(y), width(width), height(height) {}

	//ambil dr cPlayer.h
	cPlayerTest();
	~cPlayerTest();
};

