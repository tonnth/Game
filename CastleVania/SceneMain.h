#ifndef _SCENEMAIN_H_
#define _SCENEMAIN_H_

#include "Game.h"
#include "GSprite.h"
#include "Object.h"
#include "Simon.h"
#include "Map.h"
#include "GCamera.h"
#include "Medusa.h"
#include "Bat.h"
#include "IronMan.h"
#include "MorningStar.h"
class SceneMain : public CGame
{
public:
	GCamera *camera;
	Map *map;
	Simon *simon;
	Medusa *medusa;
	Bat *bat;
	IronMan *ironman;
	MorningStar *morningstar;
	SceneMain(int _nCmdShow);
	~SceneMain();

protected:
	virtual void RenderFrame(LPDIRECT3DDEVICE9 d3ddv, int t);
	virtual void ProcessInput(LPDIRECT3DDEVICE9 d3ddv, int Delta);
	virtual void LoadResources(LPDIRECT3DDEVICE9 d3ddv);

	virtual void OnKeyDown(int KeyCode);
};

#endif