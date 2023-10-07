#include <iostream>
#include <SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main( int argc, char* args[] )
{
	bool run = true;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("error initializing SDL: %s\n", SDL_GetError());
	}
	SDL_Window* win = SDL_CreateWindow("GAME",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 990, 1000, 0);
	if (win == NULL) { std::cout << "Error window creation"; }
	SDL_Renderer* renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL) { std::cout << "Error renderer creation"; }
	SDL_Rect rect = { 100,100,100,100 };
	while (run) {
		
		SDL_Event e;
		if (SDL_PollEvent(&e)) {
			SDL_RenderClear(renderer);
			if (e.type == SDL_QUIT) {
				run = false;
			}
			if (e.type == SDL_KEYDOWN) {
				if (e.key.keysym.sym == SDLK_w) {
					rect.y -= 10;
				}
				if (e.key.keysym.sym == SDLK_a) {
					rect.x -= 10;
				}
				if (e.key.keysym.sym == SDLK_s) {
					rect.y += 10;
				}
				if (e.key.keysym.sym == SDLK_d) {
					rect.x += 10;
				}
			}
		}
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &rect);

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

		SDL_RenderPresent(renderer);
		SDL_Delay(10);	
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);
	SDL_Quit();
	return 0;
}
