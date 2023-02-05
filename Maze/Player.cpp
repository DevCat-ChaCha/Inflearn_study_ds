#include "pch.h"
#include "Player.h"
#include "Board.h"

void Player::initialize(Board* board)
{
	_pos = board->getEnterPos();
	_board = board;
}

void Player::update(uint64 dt)
{

}
