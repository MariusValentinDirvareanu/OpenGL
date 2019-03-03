#include <SDL.h>
#include <iostream>

using namespace std;

int main(int argc, char * argv[]) {

	SDL_Window *window;                    // Declare a pointer

	SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

	// Create an application window with the following settings:
	window = SDL_CreateWindow(
		"An SDL2 window",                  // window title
		SDL_WINDOWPOS_UNDEFINED,           // initial x position
		SDL_WINDOWPOS_UNDEFINED,           // initial y position
		640,                               // width, in pixels
		480,                               // height, in pixels
		SDL_WINDOW_VULKAN                  // flags - see below
	);

	// Check that the window was successfully created
	if (window == NULL) {
		// In the case that the window could not be made...
		cout << "Could not create window: " << SDL_GetError() << endl;
		return 1;
	}

	// The window is open: could enter program loop here (see SDL_PollEvent())

	SDL_Event windowEvent;

	while (true) {
		if (SDL_PollEvent(&windowEvent)) {
			if (SDL_QUIT == windowEvent.type) {
				break;
			}
		}
	}

	// Close and destroy the window
	SDL_DestroyWindow(window);

	// Clean up
	SDL_Quit();
	return 0;
}