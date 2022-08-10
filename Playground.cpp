#include <Windows.h>

#include "Playground.h"
#include "Snake.h"
#include "Apple.h"

Playground::Playground() {
	HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(hConsole);
	SetSize(hConsole, hWidth, hHeight);
	ChangeTitle(L"Viiibora");

	Console = hConsole;
}

BOOL Playground::ChangeTitle(LPCTSTR title) {
	return SetConsoleTitle(title);
}

BOOL Playground::SetSize(HANDLE screen_buffer, SHORT width, SHORT height) {
	COORD const size = { width, height };
	BOOL success;

	SMALL_RECT const minimal_window = { 0, 0, 1, 1 };
	success = SetConsoleWindowInfo(screen_buffer, TRUE, &minimal_window);

	success = SetConsoleScreenBufferSize(screen_buffer, size);

	SMALL_RECT const window = { 0, 0, size.X - 1, size.Y - 1 };
	success = SetConsoleWindowInfo(screen_buffer, TRUE, &window);
	return success;
}

void Playground::Draw(wchar_t* map, const Snake& player, const Apple& apple) {
	for (int x = 0; x < hWidth; x++)
	{
		for (int y = 0; y < hHeight; y++)
		{
			if (x == 0 || x == hWidth - 1 || y == 0 || y == hHeight - 1)
			{
				map[x + (y * hWidth)] = '#';
			}
			else
			{
				if (x == apple.position.X && y == apple.position.Y) { // Draw apple
					map[x + (y * hWidth)] = 9608;
					DWORD coloured;
					FillConsoleOutputAttribute(this->Console, FOREGROUND_RED, 1, apple.position, &coloured);
				}
				else { // Draw playground empty cell
					map[x + (y * hWidth)] = '.';
				}
			}
		}
	}

	for (auto body_part : player.m_body) {
		map[body_part.X + (body_part.Y * hWidth)] = 9608; //Unicode block char
	}

	DWORD written;
	WriteConsoleOutputCharacter(this->Console, map, hWidth * hHeight, { 0, 0 }, &written);
}