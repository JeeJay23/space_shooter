#include "GPU.h"

GPU::GPU()
{
    SDL_SetMainReady();
    SDL_Init(SDL_INIT_VIDEO);

    SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

GPU::~GPU()
{
}

void GPU::draw(gameObject** obj, int objCount)
{
	SDL_RenderClear(renderer);

    for (int i = 0; i < objCount; i++) {
		// draw every object in list
		if (obj[i] == nullptr) continue;

		SDL_Rect rect;
		rect.x = obj[i]->x;
		rect.y = obj[i]->y;
		rect.w = PLACEHOLDER_SPR_SIZE;
		rect.h = PLACEHOLDER_SPR_SIZE;

		SDL_SetRenderDrawColor(renderer, 0xff, 0, 0xff, 0xff);
		SDL_RenderFillRect(renderer, &rect);
    }

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xff);
	SDL_RenderPresent(renderer);
}


void GPU::drawMap(Map* map)
{
    // draw blocks
    for (int x = 0; x < map->width; x++) {
        for (int y = 0; y < map->height; y++) {
			if (map->blocks[x][y] == nullptr) continue;

			SDL_Rect rect;
			rect.x = map->blocks[x][y]->x;
			rect.y = map->blocks[x][y]->y;
			rect.w = PLACEHOLDER_SPR_SIZE;
			rect.h = PLACEHOLDER_SPR_SIZE;

			SDL_SetRenderDrawColor(renderer, 0xff, 0, 0xff, 0xff);
			SDL_RenderFillRect(renderer, &rect);
        }
    }

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xff);
	SDL_RenderPresent(renderer);
}
