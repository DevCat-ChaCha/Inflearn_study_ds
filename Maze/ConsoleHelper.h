#pragma once
#include <Windows.h>
#include "Type.h"

enum class ConsoleColor
{
	BLACK = 0,
	RED = FOREGROUND_RED,
	BLUE = FOREGROUND_BLUE,
	GREEN = FOREGROUND_GREEN,
	YELLOW = RED | GREEN,
	WHITE = RED | GREEN | BLUE,
};


class ConsoleHelper
{
public:
	static void setCursorPosition(int32 x, int32 y);
	static void setCursorColor(ConsoleColor color);
	static void setConsoleCursor(bool flag);
};

