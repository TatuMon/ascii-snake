#include <Windows.h>
#include <ctime>

#include "Playground.h"
#include "Apple.h"

Apple::Apple() {
	srand(time(NULL));
	//short Y = rand() % (max - min + 1) + min
	short X = rand() % ((hWidth - 1) - 1 + 1) + 1;
	short Y = rand() % ((hHeight - 1) - 1 + 1) + 1;

	position = { X,Y };
}

void Apple::randomizePosition() {
	srand(time(NULL));
	//short Y = rand() % (max - min + 1) + min
	short X = rand() % ((hWidth - 1) - 1 + 1) + 1;
	short Y = rand() % ((hHeight - 1) - 1 + 1) + 1;

	position = { X,Y };
}

void Apple::eaten(Playground playground) {
	DWORD coloured;
	FillConsoleOutputAttribute(playground.Console, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED, 1, this->position, &coloured);

	randomizePosition();
}