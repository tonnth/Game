#ifndef _WEAPON_H_
#define _WEAPON_H_

#include <d3dx9.h>
#include "GSprite.h"
#include "GCamera.h"

class Weapon
{
protected:
	float x;	// Vị trí theo trục X
	float y;	// Vị trí theo trục Y#pragma once

	float Vx;	// Vận tốc theo trục X
	float Vy;	// Vận tốc theo trục Y

	float Speed; // Tốc độ
	
	int Trend;		// Phương hướng, trái = -1, phải = 1;

	GSprite* WeaponSprite;
	GTexture* Size;

public:
	Weapon();
	~Weapon();							// Hàm hủy Weapon

	int GetX();
	int GetY();
	
	float GetSpeed();
	float GetVx();
	float GetVy();

	int GetTrend();
	void SetTrend(int a);

	/*void Stop();
	void Star();
	void Attack();*/
	virtual void Update(GCamera *camera, int t);
	virtual void DrawWeapon(GCamera *camera);
};

#endif
