#include "pch.h"
#include <iostream>

#include "ConsoleHelper.h"


// github tokens
//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

int main()
{
	uint64 lastTick = 0;
	
	while (true)
	{
		// 프레임관리
		const uint64 currentTick = ::GetTickCount64();
		const uint64 deltaTick = currentTick - lastTick;
		// 고정프레임용
		if (deltaTick < 60)	continue;
		
		lastTick = currentTick;

		// 입력


		// 로직


		// 렌더링




		ConsoleHelper::setCursorPosition(0, 0);
		ConsoleHelper::setConsoleCursor(false);
		ConsoleHelper::setCursorColor(ConsoleColor::RED);

		const char* TILE = "■";
		for (int32 x = 0; x < 25; x++)
		{
			for (int32 y = 0; y < 25; y++)
			{
				cout << TILE;
			}

			cout << endl;
		}
	}
}
