#include <SDL/SDL.h>
#include <cassert>

int main()
{
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Surface * const screen{
    SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE)
  };
  assert(screen);
  SDL_Surface * const bmp{
    SDL_LoadBMP("../travis_qmake_gcc_cpp14_sdl/TravisCI.bmp")
  };
  assert(bmp);
  SDL_BlitSurface(bmp, nullptr, screen, nullptr);
  SDL_Flip(screen);
  SDL_Delay(2000);
  SDL_FreeSurface(bmp);
  SDL_Quit();
}
