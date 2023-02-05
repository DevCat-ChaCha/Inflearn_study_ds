#include "pch.h"
#include <iostream>

#include "ConsoleHelper.h"
#include "Board.h"
#include "Player.h"

Board board;
Player player;

// github tokens
//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

int main()
{
	// 랜덤 시드 설정
	::srand(static_cast<unsigned>(time(nullptr)));

	board.initialize(25, &player);
	player.initialize(&board);

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
		player.update(deltaTick);

		// 렌더링
		board.render();
	}
}
