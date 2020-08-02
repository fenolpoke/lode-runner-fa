#include "cPlayerTest.h"

#include <iostream>

using namespace std;

void cPlayerTest::Render()
{


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, playerSheet->at(animControl->Index())->Texture());

//	cout << animControl->Index() << " : " << playerSheet->at(animControl->Index())->Texture() << endl;

//	glColor3f(0, 1, 0);
	glBegin(GL_QUADS);

	/*
		glTexCoord2f(384/1024, 0.25f); glVertex3i(x, y, 50); 
		glTexCoord2f(0.375f, 0.25f); glVertex3i(x+width, y, 50);
		glTexCoord2f(0.375f, 0.125f); glVertex3i(x+width, y+height, 50); 
		glTexCoord2f(0.25f, 0.125f); glVertex3i(x, y+height, 50);
	*/

	glTexCoord2f(playerSheet->at(animControl->Index())->X0(), playerSheet->at(animControl->Index())->Y1());	glVertex3i(x, y, 49);
	glTexCoord2f(playerSheet->at(animControl->Index())->X1(), playerSheet->at(animControl->Index())->Y1());	glVertex3i(x + width, y, 49);
	glTexCoord2f(playerSheet->at(animControl->Index())->X1(), playerSheet->at(animControl->Index())->Y0());	glVertex3i(x + width, y + height, 49);
	glTexCoord2f(playerSheet->at(animControl->Index())->X0(), playerSheet->at(animControl->Index())->Y0());	glVertex3i(x, y + height, 49);


	glEnd();

	glDisable(GL_TEXTURE_2D);

}

void cPlayerTest::Init()
{
	//dr cplayer.cpp
	animControl = new cAnimControl();

	animControl->AddAnim("StraightLoop", "walk_forward", 0, 1, 0.2f);
	animControl->AddAnim("StraightLoop", "walk_backward", 25, 26, 0.2f); // 5 6 25 26 index d hitung dr ujung kiri atas k bawah
	animControl->AddAnim("NoLoop", "jump", 2, 2, 0.2f);
	animControl->AddAnim("NoLoop", "idle", 4, 4, 0.2f);
	//dr cplayer.cpp

}

void cPlayerTest::Update(float tpf)
{
	animControl->SetActiveAnim(keys[','] ? "walk_backward" : keys['.'] ? "walk_forward" : "idle");

	x -= keys[','] ? 50 * tpf : 0;
	x += keys['.'] ? 50 * tpf : 0;

	animControl->UpdateAnim(tpf);

}

void cPlayerTest::ReadKeyboard(unsigned char key, int x, int y, bool press)
{
	keys[key] = press? true : false;
}

void cPlayerTest::ReadSpecialKeyboard(unsigned char key, int x, int y, bool press)
{
}

void cPlayerTest::ReadMouse(int button, int state, int x, int y)
{
}

cPlayerTest::cPlayerTest()
{
}


cPlayerTest::~cPlayerTest()
{
}
