#include <Windows.h>
#include <memory>
#include <thread>
#include <string>

#include <iostream>

#include "Monstd.h"
#include "Playground.h"
#include "Snake.h"
#include "Apple.h"

int main() {
	Playground playground;

	bool running = true;
	bool paused = false;

	//Read input and update snake body
	std::thread eventsThread([&playground, running] { while (running) playground.PollSnakeMovement(); });

	while (running)
	{
		std::this_thread::sleep_for(Seconds(0.1f));
		
		playground.MoveSnake();
		playground.Draw();
	}

	playground.unloadGameObjects();
}
