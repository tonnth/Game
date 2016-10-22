#include "SceneMain.h"

SceneMain::SceneMain(int _nCmdShow) : CGame(_nCmdShow)
{

}

void SceneMain::RenderFrame(LPDIRECT3DDEVICE9 d3ddv, int t)
{
	d3ddv->ColorFill(G_BackBuffer, NULL, D3DCOLOR_XRGB(0, 0, 0));

	simon->Update(camera, t);
	morningstar->Update(camera, t, simon->GetX(), simon->GetY(), simon->GetTrend());
    camera->SetVCam(simon->GetVx());
	camera->SetFolowPos(simon->GetX(),simon->GetY());
	camera->UpdateCamera();

	medusa->Update(camera, t);
	bat->Update(camera, t);
	ironman->Update(camera, t);

	G_SpriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

	map->DrawMap(camera);
	simon->DrawObject(camera);
	if (simon->GetAttacking() == 1)
		morningstar->DrawWeapon(camera);
	medusa->DrawObject(camera);
	bat->DrawObject(camera);
	ironman->DrawObject(camera);

	G_SpriteHandler->End();
}

void SceneMain::ProcessInput(LPDIRECT3DDEVICE9 d3ddv, int Delta)
{
	if (IsKeyDown(DIK_LEFT))
	{
		simon->MoveLeft();
		bat->Stop();
	}
	else
	if (IsKeyDown(DIK_RIGHT))
	{
		simon->MoveRigh();
		bat->Stop();
	}
	else
	{
		simon->Stop();
		bat->Star();
	}

	if (IsKeyDown(DIK_NUMPADENTER) || IsKeyDown(DIK_D))
	{
		simon->Attack();
	}
}

void SceneMain::LoadResources(LPDIRECT3DDEVICE9 d3ddv)
{
	map = new Map();
	camera = new GCamera();
	camera->SetSizeMap(G_MapWidth, 0);

	simon = new Simon();
	morningstar = new MorningStar(simon->GetX(), simon->GetY(), simon->GetTrend());
	medusa = new Medusa();
	medusa->Star();
	bat = new Bat();
	ironman = new IronMan();
	ironman->Star();
}

void SceneMain::OnKeyDown(int KeyCode)
{

}

SceneMain::~SceneMain(void)
{
}
