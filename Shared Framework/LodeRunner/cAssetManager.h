// Copyright 2015 Kelvin Chandra, Software Laboratory Center, Binus University. All Rights Reserved.
#pragma once

#include "cTexture.h"
#include "Globals.h"
#include "cSprite.h"

//Image array size
#define NUM_TEX		 1
//Image identifiers
#define SPRITESHEET_PLAYERS	1

/*
//Image array size
#define NUM_TEX		 3
//Image identifiers
#define SPRITESHEET_PLAYERS	1
#define SPRITESHEET_HOUSES	3
#define SPRITESHEET_DOGS	4
*/
class cAssetManager
{
public:
	static cAssetManager& getInstance()
	{
		static cAssetManager instance;
		return instance;
	}

	int  GetID(int img);
	void GetSize(int img, int *w, int *h);
	bool Load();

	std::vector<cSprite*> *player = new std::vector<cSprite*>;
private:
	~cAssetManager(void);
	cAssetManager(void);
	cAssetManager(cAssetManager const&) = delete;
	void operator=(cAssetManager const&) = delete;


	cTexture textures[NUM_TEX];
	bool LoadImage(int img, char *filename, int type = GL_RGBA);
};
