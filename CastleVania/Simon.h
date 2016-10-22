#ifndef _SIMON_H_
#define _SIMON_H_

#include <d3dx9.h>
#include "GSprite.h"
#include "Object.h"
	
#define SIMON_IMAGE_FILE "Resources/simon.png"
#define SIMON_TREND 0
#define SIMON_FRAME 100
#define SIMON_STOP_IMAGE 0

#define SIMON_STOP_IMAGE 0

#define SIMON_X 50
#define SIMON_Y 64

#define SIMON_VX 3.0f
#define SIMON_VX_STAIR 43	
#define SIMON_VY_STAIR 43
#define SIMON_VJUMP 450
#define SIMON_GRAVITY 20
#define SIMON_FALL 180
#define SIMON_VX_DAMAGED 150
#define SIMON_VY_DAMAGED 450

class Simon : public Object
{
	
public:
	Simon();
	Simon(float x, float y);
	~Simon();

	virtual void Update(GCamera *camera,int t);
	virtual void DrawObject(GCamera *camera);
};
#endif
