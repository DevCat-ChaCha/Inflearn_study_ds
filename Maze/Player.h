#pragma once

class Board;

class Player
{
	enum
	{
		TICK = 100
	};

public:
	void initialize(Board* board);
	void update(uint64 dt);

	void setPos(Pos pos) { _pos = pos; }
	Pos getPos() { return _pos; }

	bool canGo(Pos pos);

private:
	Pos _pos = {};
	int32 _dir = DIR_UP;
	Board* _board = nullptr;


	vector<Pos> _path;
	int _pathIndex = 0;
	int64_t _sumTick = 0;
};

