#include <Windows.h>
#include <memory>
#include <thread>
#include <string>

#include "Monstd.h"
#include "Playground.h"
#include "Snake.h"
#include "Apple.h"

//TO-DO/FIX
// 1- Snake can turn on the same axis
// 2- Snake collision with itself
// 4- Pause button

int main() {
	CharMap map = std::make_unique<wchar_t[]>(hWidth * hHeight);
	Playground playground;

	Snake player = Snake();

	bool running = true;
	bool paused = false;

	//Read input and update snake body
	std::thread eventsThread([&player, running] { while (running) player.PollMovementEvent(); });

	while (running)
	{
		std::this_thread::sleep_for(Seconds(0.1f));
		playground.Draw(map.get(), player, apple);
		
		player.Move();
	}
}
