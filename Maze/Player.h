#pragma once

class Board;

class Player
{
public:
	void initialize(Board* board);
	void update(uint64 dt);

	void setPos(Pos pos) { _pos = pos; }
	Pos getPos() { return _pos; }

private:
	Pos _pos = {};
	Dir _dir = DIR_UP;
	Board* _board = nullptr;
};

