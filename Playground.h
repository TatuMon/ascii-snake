#pragma once

unsigned char hWidth = 60;
unsigned char hHeight = 15;

struct Playground {
	HANDLE Console;

	Playground();

	BOOL ChangeTitle(LPCTSTR title);

	BOOL SetSize(HANDLE screen_buffer, SHORT width, SHORT height);

	void Draw(wchar_t* map, const Snake& player, const Apple& apple);
};

