#include <stdio.h>
#include "SDL2/SDL.h"
#include "lua.h"
#include "lauxlib.h"

int main(int argc, char** argv) {
  if (SDL_Init(SDL_INIT_EVERYTHING) == -1){
    printf("%s\n", SDL_GetError());
    return 1;
  }

	lua_State* state = luaL_newstate();
  luaL_dofile(state, "title.lua");
  lua_getglobal(state, "title");
  lua_call(state, 0, 1);

  SDL_Window *win = 0;
  win = SDL_CreateWindow(lua_tolstring(state, 1, NULL), 100, 100, 640, 480, SDL_WINDOW_SHOWN);
  if (win == 0){
    printf("%s\n", SDL_GetError());
    return 1;
  }
  SDL_Renderer *ren = 0;
  ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (ren == 0){
    printf("%s\n", SDL_GetError());
    return 1;
  }
  SDL_Delay(2000);
  SDL_DestroyRenderer(ren);
  SDL_DestroyWindow(win);
  SDL_Quit();
  return 0;
}
