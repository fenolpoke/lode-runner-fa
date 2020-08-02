// Copyright 2015 Kelvin Chandra, Software Laboratory Center, Binus University. All Rights Reserved.
#include "cLevel1Scene.h"
#include "cAssetManager.h"
#include "cGame.h"
#include "cMenuScene.h"
#pragma warning(disable:4996)

cLevel1Scene::cLevel1Scene()
{

}

cLevel1Scene::~cLevel1Scene()
{
}

void cLevel1Scene::Init()
{
	player = new cPlayer(cAssetManager::getInstance().player, 100, 200, 2 * TILE_SIZE, 4 * TILE_SIZE);
	player->Init();
}

void cLevel1Scene::Render()
{
	player->Render();
}



void cLevel1Scene::Update(float tpf /*= 0.0333*/)
{
	player->Update();

}

void cLevel1Scene::ReadKeyboard(unsigned char key, int x, int y, bool press)
{
	player->ReadKeyboard(key, x, y, press);
	if (press)
	{
		keys[key] = true;
	}
	else
	{
		keys[key] = false;
	}
}

void cLevel1Scene::ReadSpecialKeyboard(unsigned char key, int x, int y, bool press)
{
	player->ReadSpecialKeyboard(key, x, y, press);
	if (press)
	{
		keys[key] = true;
	}
	else
	{
		keys[key] = false;
	}
}

void cLevel1Scene::ReadMouse(int button, int state, int x, int y)
{
	player->ReadMouse(button, state, x, y);
}

