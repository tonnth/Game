#include "Medusa.h"

Medusa::Medusa()
{
	this->x =MEDUSA_X;
	this->y = MEDUSA_Y;
	
	Vx = 0;
	Vy = 0;
	Speed = MEDUSA_VX;

	Size = new GTexture(MEDUSA_IMAGE_FILE, 2, 1, 2);
	ObjectSprite = new GSprite(Size, MEDUSA_FRAME);

	IsMoving = 0;
	Trend = MEDUSA_TREND;
}

void Medusa::Update(GCamera *camera,int t)
{
	x += Vx;
	y = sin(x*0.03)*95.5+190;

	D3DXVECTOR2 pos = camera->Transform(x, y);
	if (IsMoving != 0)
	{
		if (pos.x <= 0) this->MoveRigh();
		if (pos.x >= G_ScreenWidth) this->MoveLeft();

		ObjectSprite->Update(t);
	}
	else ObjectSprite->SelectIndex(MEDUSA_STOP_IMAGE);
}

void Medusa::DrawObject(GCamera *camera)
{
	D3DXVECTOR2 pos = camera->Transform(x, y);
	if (Trend == -1) ObjectSprite->Draw(pos.x, pos.y);
	else ObjectSprite->DrawFlipX(pos.x, pos.y);
}


