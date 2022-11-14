#pragma once
#include <deque>
#include "Monstd.h"

struct Snake {
	Snake(int nSize = 5);

	void Move();

	void PollMovementEvent();

	int m_size;
	std::deque<iCOORD> m_body;
	CardinalDirection m_facing;

	bool skipTailRemoval = false;
};