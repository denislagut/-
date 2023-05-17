#include "Library.h"

int main(int argc, char** argv) {
	const int Height = 700, Width = 1200;
		SDL_Init(SDL_INIT_EVERYTHING);
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			cout<<"SDL не смог запуститься! SDL_Error: %s\n"<< SDL_GetError();
		}
		SDL_Window* window = SDL_CreateWindow(u8"Построение графиков функций",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			Width, Height, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			cout << "Окно не может быть создано! SDL_Error: %s\n" << SDL_GetError();
		}
		SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

		Main(window, renderer);

		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 0;
}
