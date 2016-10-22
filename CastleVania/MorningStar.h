#ifndef _MORNINGSTAR_H_
#define _MORNINGSTAR_H_

#include <d3dx9.h>
#include "GSprite.h"
#include "Weapon.h"

#define MORNINGSTAR_IMAGE_FILE "Resources/morningstar.png"
#define MORNINGSTAR_TREND 0
#define MORNINGSTAR_FRAME 500
#define MORNINGSTAR_STOP_IMAGE 0


#define MORNINGSTAR_X 50
#define MORNINGSTAR_Y 64


#define MORNINGSTAR_VJUMP 450
#define MORNINGSTAR_GRAVITY 20
#define MORNINGSTAR_FALL 180
#define MORNINGSTAR_VX_DAMAGED 150
#define MORNINGSTAR_VY_DAMAGED 450

class MorningStar : public Weapon
{

public:
	MorningStar();
	MorningStar(float x, float y, int trend);
	~MorningStar();

	virtual void Update(GCamera *camera, int t, float sm_x, float sm_y, int sm_trend);
	virtual void DrawWeapon(GCamera *camera);
};
#endif

