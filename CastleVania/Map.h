#ifndef _MAP_H_
#define _MAP_H_

#include <stdio.h>
#include <conio.h>
#include "GSprite.h"
#include "GTexture.h"
#include "GCamera.h"

#define MATRIXTXT "Resources/Matrix.txt"
#define TILEMAP "Resources/1.png"
#define COLMN 48
#define ROW 10

class Map
{
private:
	GTexture *TileTexture;
	GSprite *Tile;
	int Maxcolumn;
	int TileMap[50][50];
public:
	Map();
	~Map();
	void ReadMatrix();
	void LoadMap();
	void DrawMap(GCamera *camera);
};

#endif
