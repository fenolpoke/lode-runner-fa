#include "cSceneTest.h"
#include "cGame.h"
#include<iostream>
#include "cPlayerTest.h"
using namespace std;

cSceneTest::cSceneTest()
{

	player = new cPlayerTest(cAssetManager::getInstance().player,50,50,100,200);

}


cSceneTest::~cSceneTest()
{
}

void cSceneTest::Init()
{
	cout << "masuk scene" << endl;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	visible_area.top = GAME_HEIGHT;
	visible_area.bottom = 0;
	visible_area.left = 0;
	visible_area.right = GAME_WIDTH;
	glOrtho(visible_area.left, visible_area.right, visible_area.bottom, visible_area.top, 3, -101);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	player->Init();
}

void cSceneTest::Update(float tpf/* = 0.0333*/)
{
//	cout << "update scene" << endl;
	player->Update();
}

void cSceneTest::Render()
{
//	cout << "render scene" << endl;
	player->Render();
}

void cSceneTest::ReadKeyboard(unsigned char key, int x, int y, bool press)
{
	player->ReadKeyboard(key, x, y, press);
}

void cSceneTest::ReadSpecialKeyboard(unsigned char key, int x, int y, bool press)
{
	player->ReadSpecialKeyboard(key, x, y, press);
}

void cSceneTest::ReadMouse(int button, int state, int x, int y)
{
	player->ReadMouse(button, state, x, y);
}
