#include "MorningStar.h"

MorningStar::MorningStar() {}
MorningStar::MorningStar(float x, float y, int trend)
{
	Size = new GTexture(MORNINGSTAR_IMAGE_FILE, 3, 3, 9);
	WeaponSprite = new GSprite(Size, MORNINGSTAR_FRAME);

	this->x = x;
	this->y = y;

	Trend = trend;
}
void MorningStar::Update(GCamera *camera, int t, float sm_x, float sm_y, int sm_trend)
{
	x = sm_x;
	y = sm_y;
	Trend = sm_trend;
	if (WeaponSprite->_index < 6) WeaponSprite->_index = 6; // Start attack, frame 
	WeaponSprite->Update(t);

}

void MorningStar::DrawWeapon(GCamera *camera)
{
	D3DXVECTOR2 pos = camera->Transform(x, y);
	if (Trend == -1) WeaponSprite->Draw(pos.x, pos.y);
	else WeaponSprite->DrawFlipX(pos.x, pos.y);
}
