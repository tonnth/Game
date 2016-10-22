#include "Simon.h"

Simon::Simon()
{
	Vx = 0;
	Vy = 0;
	
	Size = new GTexture(SIMON_IMAGE_FILE, 8, 3, 24);
	ObjectSprite = new GSprite(Size, SIMON_FRAME);

	this->x = SIMON_X;  
	this->y = SIMON_Y;

	Speed = SIMON_VX;
	IsMoving = 0;
	Trend = SIMON_TREND;
}

void Simon::Update(GCamera *camera,int t)
{
	if (IsAttacking == 1) //Đang ở trạng thái tấn công
	{
		if (ObjectSprite->_index < 5) ObjectSprite->_index = 5; // Bắt đầu tấn công
		if (ObjectSprite->_index > 7) // Kết thúc tấn công
		{
			IsAttacking = 0;
			ObjectSprite->SelectIndex(SIMON_STOP_IMAGE);
		}
		else ObjectSprite->Update(t);
	}
	else
	{
		if (IsMoving == 1)
		{
			x += Vx;
			y += Vy;
			D3DXVECTOR2 pos = camera->Transform(x, y);
			if (pos.x <= Size->FrameWidth / 4 || pos.x > G_ScreenWidth - Size->FrameWidth / 4) x -= Vx;

			if (ObjectSprite->_index > 3) ObjectSprite->_index = 0;
			ObjectSprite->Update(t);
		}
		else ObjectSprite->SelectIndex(SIMON_STOP_IMAGE);
	}
}

void Simon::DrawObject(GCamera *camera)
{
	D3DXVECTOR2 pos = camera->Transform(x, y);
	if (Trend == -1) ObjectSprite->Draw(pos.x, pos.y);
	else ObjectSprite->DrawFlipX(pos.x, pos.y);
}
