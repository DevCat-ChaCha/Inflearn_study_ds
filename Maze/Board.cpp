#include "pch.h"
#include "Board.h"
#include "ConsoleHelper.h"
#include "Player.h"

const char* TILE = "��";

Board::Board()
{
}

Board::~Board()
{
}

void Board::initialize(int32 size, Player* player)
{
	_size = size;
	_player = player;

	// �� ����
	generateMap();
}

void Board::render()
{
	ConsoleHelper::setCursorPosition(0, 0);
	ConsoleHelper::setConsoleCursor(false);
	ConsoleHelper::setCursorColor(ConsoleColor::RED);

	for (int32 x = 0; x < 25; x++)
	{
		for (int32 y = 0; y < 25; y++)
		{
			ConsoleColor color = getTileColor(Pos{ x,y });
			ConsoleHelper::setCursorColor(color);

			cout << TILE;
		}
		cout << endl;
	}
}

// Binary Tree �̷� ���� �˰���
//

void Board::generateMap()
{
	for (int x = 0; x < _size; x++)
	{
		for (int y = 0; y < _size; y++)
		{
			if (x == 0 || y == 0 || x == _size - 1 || y == _size - 1)
			{
				_tile[x][y] = TileType::WALL;
			}
			else if(x % 2 == 0 || y % 2 == 0)
			{
				_tile[x][y] = TileType::WALL;
			}
			else
			{
				_tile[x][y] = TileType::EMPTY;
			}
		}
	}

	for (int x = 0; x < _size; x++)
	{
		for (int y = 0; y < _size; y++)
		{
			if (x % 2 == 0 || y % 2 == 0)
			{
				continue;
			}

			if (x == _size-2 && y == _size-2)
			{
				_tile[x][y] = TileType::EXIT;
				continue;
			}

			// �� �Ʒ��� �������� �� ���������θ� ������
			if (x == _size - 2)
			{
				_tile[x][y+1] = TileType::EMPTY;
				continue;
			}

			// �� �����ʿ� �������� �� �Ʒ��θ� ������
			if (y == _size - 2)
			{
				_tile[x+1][y] = TileType::EMPTY;
				continue;
			}

			// �������̳� �Ʒ������� �ո����� ����
			const int32 randValue = rand() % 2;
			if (randValue == 0)
			{
				_tile[x][y + 1] = TileType::EMPTY;
			}
			else
			{
				_tile[x+1][y] = TileType::EMPTY;
			}

			if (getEnterPos().x == x && getEnterPos().y == y)
			{
				_tile[x][y] = TileType::ENTER;
			}
		}
	}
}

TileType Board::getTileType(Pos pos)
{
	if (pos.x < 0 || pos.x >= _size || pos.y < 0 || pos.y >= _size)
	{
		return TileType::NONE;
	}

	return _tile[pos.x][pos.y];
}

ConsoleColor Board::getTileColor(Pos pos)
{
	if(_player == nullptr)	return ConsoleColor::WHITE;

	// �÷��̾� ��ġ
	if (_player->getPos() == pos)	return ConsoleColor::YELLOW;

	TileType tileType = getTileType(pos);

	switch (tileType)
	{
		case TileType::EMPTY:
		{
			return ConsoleColor::GREEN;
		}
		break;
		case TileType::WALL:
		{
			return ConsoleColor::RED;
		}
		case TileType::ENTER:
		{
			return ConsoleColor::BLACK;
		}
		break;
		case TileType::EXIT:
		{
			return ConsoleColor::BLUE;
		}
		break;
		default:
		break;
	}

	return ConsoleColor::WHITE;
}
