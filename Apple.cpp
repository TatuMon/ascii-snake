#include <Windows.h>
#include <ctime>

#include "Apple.h"

Apple::Apple(unsigned char maxWidth, unsigned char maxHeight) {
	srand(time(NULL));
	//short Y = rand() % (max - min + 1) + min
	short X = rand() % ((maxWidth - 1) - 1 + 1) + 1;
	short Y = rand() % ((maxHeight - 1) - 1 + 1) + 1;

	maxCoords = { maxWidth, maxHeight };
	position = { X,Y };
}

void Apple::randomizePosition() {
	srand(time(NULL));
	//short Y = rand() % (max - min + 1) + min
	short X = rand() % ((maxCoords.X - 1) - 1 + 1) + 1;
	short Y = rand() % ((maxCoords.Y - 1) - 1 + 1) + 1;

	position = { X,Y };
}

void Apple::eaten() {
	randomizePosition();
}