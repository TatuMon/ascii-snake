#include <Windows.h>

#include "Snake.h"
#include "Playground.h"

Snake::Snake(int nSize) {
	m_size = nSize;
	m_facing = EAST;

	for (int i = 0; i < m_size; i++) {
		iCOORD bodypart = { (hWidth / 2 - i), (hHeight / 2) };
		m_body.push_back(bodypart);
	}
}

/// <summary>
/// Move the head component of m_body one char
/// in direction of m_facing.
/// </summary>
void Snake::Move() {
	iCOORD newPos;

	switch (this->m_facing) {
	case NORTH:
	{
		//Check boundary
		newPos = { this->m_body.front().X, this->m_body.front().Y - 1 };
		if (newPos.Y < 0) {
			newPos.Y = hHeight;
		}
	}
	break;
	case EAST:
	{
		newPos = { this->m_body.front().X + 1, this->m_body.front().Y };
	}
	break;
	case SOUTH:
	{
		newPos = { this->m_body.front().X, this->m_body.front().Y + 1 };
		//Check boundary
		if (newPos.Y > hHeight) {
			newPos.Y = 0;
		}
	}
	break;
	case WEST:
	{
		newPos = { this->m_body.front().X - 1, this->m_body.front().Y };
	}
	break;
	}

	this->m_body.push_front(newPos);

	if (!this->skipTailRemoval)
	{
		this->m_body.pop_back();
	}

	this->skipTailRemoval = false;
}

void Snake::PollMovementEvent() {
	if (GetKeyState(VK_UP) & 0x8000) {
		if (this->m_facing != SOUTH) {
			this->m_facing = NORTH;
		}
	}
	else if (GetKeyState(VK_RIGHT) & 0x8000) {
		if (this->m_facing != WEST) {
			this->m_facing = EAST;
		}
	}
	else if (GetKeyState(VK_DOWN) & 0x8000) {
		if (this->m_facing != NORTH) {
			this->m_facing = SOUTH;
		}
	}
	else if (GetKeyState(VK_LEFT) & 0x8000) {
		if (this->m_facing != EAST) {
			this->m_facing = WEST;
		}
	}
}