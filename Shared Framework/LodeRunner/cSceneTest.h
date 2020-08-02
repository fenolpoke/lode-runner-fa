#pragma once
#include "cScene.h"
#include "cRect.h"
#include "cPlayerTest.h"
#include "cAssetManager.h"

class cSceneTest :
	public cScene
{
public:
	cSceneTest();
	~cSceneTest();

	// Inherited via cScene
	virtual void Init() override;
	virtual void Update(float tpf = 0.0333) override;
	virtual void Render() override;
	virtual void ReadKeyboard(unsigned char key, int x, int y, bool press) override;
	virtual void ReadSpecialKeyboard(unsigned char key, int x, int y, bool press) override;
	virtual void ReadMouse(int button, int state, int x, int y) override;

	cRect visible_area;
	cPlayerTest *player /*= new cPlayer()*/;
};

