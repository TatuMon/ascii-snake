#pragma once

#include "Apple.h"
#include "Snake.h"

extern unsigned char hWidth;
extern unsigned char hHeight;

struct Playground {
	HANDLE Console;

	Playground();

	void loadGameObjects();

	void unloadGameObjects();

	BOOL ChangeTitle(LPCTSTR title);

	BOOL SetSize(HANDLE screen_buffer, SHORT width, SHORT height);

	void setCellBackToBlack(COORD cell);

	void Draw(wchar_t* map);

	void PollSnakeMovement();

	void MoveSnake();

	bool SnakeAteApple();

private:
	Snake* m_snake;
	Apple* m_apple;
};

