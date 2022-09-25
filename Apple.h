#pragma once


struct Apple {
	Apple(unsigned char maxWidth, unsigned char maxHeight);
	void randomizePosition();
	void eaten();

	COORD maxCoords;
	COORD position;
};
