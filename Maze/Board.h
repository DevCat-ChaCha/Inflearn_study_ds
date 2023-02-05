#pragma once
#include "ConsoleHelper.h"

class Player;

enum
{
	BOARD_MAX_SIZE = 100,
};

// 현재 위치가 벽인지 뚫려있는지 체크(갈 수 있는 공간, 갈 수 없는 공간)
enum class TileType
{
	NONE = 0,
	EMPTY = 1,
	WALL = 2,
	ENTER = 3,
	EXIT = 4,
};

class Board
{
public:
	Board();
	~Board();

	void initialize(int32 size, Player* player);
	void render();

	void generateMap();
	TileType getTileType(Pos pos);
	ConsoleColor getTileColor(Pos pos);

	Pos getEnterPos() { return Pos{ 1,1 }; }
	Pos getExitPos() { return Pos{ _size - 2, _size - 2}; }

private:
	TileType _tile[BOARD_MAX_SIZE][BOARD_MAX_SIZE];
	int32	 _size = 0;
	Player* _player = nullptr;

};

