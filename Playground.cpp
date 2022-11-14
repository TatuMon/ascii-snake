#include <Windows.h>

#include "Playground.h"
#include "Snake.h"
#include "Apple.h"

unsigned char hWidth = 60;
unsigned char hHeight = 15;

Playground::Playground()
{
	this->loadGameObjects();
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	SetSize(hConsole, hWidth, hHeight);
	ChangeTitle(L"Viiibora");

	Console = hConsole;
}

void Playground::loadGameObjects()
{
	Snake* player = new Snake();
	Apple* apple = new Apple(hWidth, hHeight);

	this->m_snake = player;
	this->m_apple = apple;
}

void Playground::unloadGameObjects()
{
	delete this->m_snake;
	delete this->m_apple;
}

BOOL Playground::ChangeTitle(LPCTSTR title)
{
	return SetConsoleTitle(title);
}

BOOL Playground::SetSize(HANDLE screen_buffer, SHORT width, SHORT height)
{
	COORD const size = { width, height };
	BOOL success;

	SMALL_RECT const minimal_window = { 0, 0, 1, 1 };
	success = SetConsoleWindowInfo(screen_buffer, TRUE, &minimal_window);

	success = SetConsoleScreenBufferSize(screen_buffer, size);

	SMALL_RECT const window = { 0, 0, size.X - 1, size.Y - 1 };
	success = SetConsoleWindowInfo(screen_buffer, TRUE, &window);
	return success;
}

void Playground::setCellBackToBlack(COORD cell)
{
	DWORD coloured;
	FillConsoleOutputAttribute(Console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED, 1, cell, &coloured);
}

void Playground::Draw(wchar_t* map)
{
	for (int x = 0; x < hWidth; x++)
	{
		for (int y = 0; y < hHeight; y++)
		{
			if (x == this->m_apple->position.X && y == this->m_apple->position.Y) // Draw apple
			{
				map[x + (y * hWidth)] = 9608;
				DWORD coloured;
				FillConsoleOutputAttribute(this->Console, FOREGROUND_RED, 1, this->m_apple->position, &coloured);
			}
			else // Draw playground empty cell
			{ 
				map[x + (y * hWidth)] = '.';
			}
		}
	}

	for (auto body_part : this->m_snake->m_body)
	{
		map[body_part.X + (body_part.Y * hWidth)] = 9608; //Unicode block char
	}

	DWORD written;
	WriteConsoleOutputCharacter(this->Console, map, hWidth * hHeight, { 0, 0 }, &written);
}

/// Se debería llamar desde otro hilo diferente al que se usa para dibujar
void Playground::PollSnakeMovement()
{
	this->m_snake->PollMovementEvent();
}

void Playground::MoveSnake()
{
	this->SnakeAteApple();
	this->m_snake->Move();
}

bool Playground::SnakeAteApple()
{
	if (this->m_snake->m_body.front().X == this->m_apple->position.X && this->m_snake->m_body.front().Y == this->m_apple->position.Y)
	{
		this->setCellBackToBlack(this->m_apple->position);
		this->m_apple->eaten();
		this->m_snake->skipTailRemoval = true;
		return true;
	}

	return false;
}