#include "pch.h"
#include "Player.h"
#include "Board.h"

void Player::initialize(Board* board)
{
	// �� ��¥ ��ǥ
	_pos = board->getEnterPos();
	_board = board;

	// �̸� ���� �� ã�Ƴ��������� update ���� �����̱�
	
	// �̵� �ùķ��̼ǿ��� ���� - ���� ��ǥ
	Pos pos = _pos;

	// �������� �����ϱ� ������ ��� ����
	Pos destination = board->getExitPos();

	_path.clear();
	_path.push_back(pos);

	Pos front[4] =
	{
		// ������ enum �� �����ϰ�
		Pos {-1, 0}, // UP
		Pos {0, -1}, // LEFT
		Pos {1, 0}, // DOWN
		Pos {0, 1}, // RIGHT
	};

	int32 newDir = 0;
	while (pos != destination)
	{
		// ������ �������� 90 ȸ�� �� üũ
		newDir = (_dir - 1 + DIR_COUNT) % DIR_COUNT;

		// 1. ���� �ٶ󺸴� ������ �������� ���������� ������ �� �ִ��� Ȯ��.
		if (canGo(pos + front[newDir]) == true)
		{
			// ���ο� �������� ���� �ٲ���
			_dir = newDir;
			// ����
			pos += front[newDir];

			_path.push_back(pos);
		}
		// 2. �װ� �ƴ϶�� ���� �ٶ󺸴� ������ �������� ������ �� �ִ��� Ȯ��.
		else if (canGo(pos + front[_dir]) == true)
		{
			// ������ �ٲ��� �ʿ�� ����
			// 
			// ����
			pos += front[_dir];

			_path.push_back(pos);
		}
		// 3. ���� �������� �����̰� �ȴ�.
		else
		{
			// ���� �������� 90 ȸ��
			_dir = (_dir + 1) % DIR_COUNT;
			// ������ ���� �ʴ´�
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
		// �̵� �ڵ�
		_pos = _path[_pathIndex];
		_pathIndex++;

		_sumTick = 0;
	}

}
