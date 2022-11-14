#pragma once
#include <memory>
#include <chrono>

typedef std::chrono::duration<float> Seconds;
typedef wchar_t* CharMap;

enum CardinalDirection {
	NORTH,
	EAST,
	SOUTH,
	WEST
};

/// <summary>
/// Same as COORD but with integers
/// </summary>
struct iCOORD {
	int X;
	int Y;

	bool operator==(iCOORD other) {
		if ((this->X == other.X) && (this->Y == other.Y)) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator==(COORD other) {
		if ((this->X == other.X) && (this->Y == other.Y)) {
			return true;
		}
		else {
			return false;
		}
	}
};