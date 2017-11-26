#include "wolf3d.h"
int main(int argc, char* argv[]) {

  SDL_Event event;
  SDL_Renderer *renderer;
  SDL_Window *window;
  int i;

  SDL_Init(SDL_INIT_VIDEO);
  SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer);
  SDL_SetRenderDrawColor(renderer,
  SDL_RenderClear(renderer);
  SDL_SetRenderDrawColor(renderer, 100, 0, 0, 100);
  for (i = 0; i < WINDOW_HEIGHT; ++i)
      SDL_RenderDrawPoint(renderer, i, 76);
      SDL_RenderPresent(renderer);
  while (1) {
      if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
          break;
  }
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return EXIT_SUCCESS;
    return 0;
}
