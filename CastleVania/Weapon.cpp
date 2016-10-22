#include "Weapon.h"

Weapon::Weapon()
{
}

Weapon::~Weapon()
{
	delete WeaponSprite;
	delete Size;
}

int Weapon::GetX()
{
	return x;
}

int Weapon::GetY()
{
	return y;
}

void Weapon::Update(GCamera *camera, int t)
{
}

void Weapon::DrawWeapon(GCamera *camera)
{
}


int Weapon::GetTrend()
{
	return Trend;
}

void Weapon::SetTrend(int a)
{
	Trend = a;
}
float Weapon::GetSpeed()
{
	return Speed;
}

float Weapon::GetVx()
{
	return Vx;
}

float Weapon::GetVy()
{
	return Vy;
}




