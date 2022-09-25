#pragma once

#include "Apple.h"
#include "Snake.h"

extern unsigned char hWidth;
extern unsigned char hHeight;

struct Playground {
	HANDLE Console;

	Playground();

	BOOL ChangeTitle(LPCTSTR title);

	BOOL SetSize(HANDLE screen_buffer, SHORT width, SHORT height);

	void setCellBackToWhite(COORD cell);

	void Draw(wchar_t* map, const Snake& player, const Apple& apple);
};

