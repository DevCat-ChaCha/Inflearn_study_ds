#include "pch.h"
#include "Player.h"
#include "Board.h"

void Player::initialize(Board* board)
{
	// 내 진짜 좌표
	_pos = board->getEnterPos();
	_board = board;

	// 미리 길을 다 찾아놓은다음에 update 에서 움직이기
	
	// 이동 시뮬레이션에서 쓰일 - 현재 좌표
	Pos pos = _pos;

	// 목적지에 도착하기 전에는 계속 실행
	Pos destination = board->getExitPos();

	_path.clear();
	_path.push_back(pos);

	Pos front[4] =
	{
		// 순서는 enum 과 동일하게
		Pos {-1, 0}, // UP
		Pos {0, -1}, // LEFT
		Pos {1, 0}, // DOWN
		Pos {0, 1}, // RIGHT
	};

	int32 newDir = 0;
	while (pos != destination)
	{
		// 오른쪽 방향으로 90 회전 후 체크
		newDir = (_dir - 1 + DIR_COUNT) % DIR_COUNT;

		// 1. 현재 바라보는 방향을 기준으로 오른쪽으로 움직일 수 있는지 확인.
		if (canGo(pos + front[newDir]) == true)
		{
			// 새로운 방향으로 방향 바꿔줌
			_dir = newDir;
			// 전진
			pos += front[newDir];

			_path.push_back(pos);
		}
		// 2. 그게 아니라면 현재 바라보는 방향을 기준으로 전진할 수 있는지 확인.
		else if (canGo(pos + front[_dir]) == true)
		{
			// 방향을 바꿔줄 필요는 없다
			// 
			// 전진
			pos += front[_dir];

			_path.push_back(pos);
		}
		// 3. 왼쪽 방향으로 움직이게 된다.
		else
		{
			// 왼쪽 방향으로 90 회전
			_dir = (_dir + 1) % DIR_COUNT;
			// 전진은 하지 않는다
		}
	}

}

bool Player::canGo(Pos pos)
{
	if (_board == nullptr) return false;

	TileType type = _board->getTileType(pos);

	if (type == TileType::EMPTY || type == TileType::EXIT)
	{
		return true;
	}
}

void Player::update(uint64 dt)
{
	if (_pathIndex >= _path.size())	return;

	_sumTick += dt;

	if (_sumTick >= TICK)
	{
		// 이동 코드
		_pos = _path[_pathIndex];
		_pathIndex++;

		_sumTick = 0;
	}

}
