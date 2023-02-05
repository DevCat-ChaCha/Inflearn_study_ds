#pragma once

//  공용으로 사용할 헤더를 여기에 모두 넣어준다

#include <Windows.h>
#include <iostream>
#include <vector>

#include "Type.h"

using namespace std;

// position 구조체 좌표관리용
struct Pos
{
	bool operator == (Pos& other)
	{
		return y == other.y && x == other.x;
	}

	bool operator != (Pos& other)
	{
		return !(*this == other);
	}

	Pos operator+(Pos& other)
	{
		Pos ret;
		ret.x = x + other.x;
		ret.y = y + other.y;

		return ret;
	}

	Pos& operator+=(Pos& other)
	{
		x += other.x;
		y += other.y;

		return *this;
	}

	int32 x = 0;
	int32 y = 0;
};

enum Dir
{
	// 시계방향 순서
	DIR_UP = 0,
	DIR_LEFT = 1,
	DIR_DOWN = 2,
	DIR_RIGHT = 3,

	DIR_COUNT = 4,
};