//made by Nabir14
#include <iostream>
#include <SDL.h>
using namespace std;
int main()
{
	SDL_Window *window = nullptr;
	SDL_Surface *windowSurface = nullptr;
	SDL_Surface *imageSurface = nullptr;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "error" << endl;
	}
	else
	{
		window = SDL_CreateWindow("SDL_Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 400, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			cout << "error" << endl;
		}
		else
		{
			windowSurface = SDL_GetWindowSurface(window);
			imageSurface = SDL_LoadBMP("test.bmp");
			if (imageSurface == NULL)
			{
				cout << "error" << endl;
			}
			else
			{
				SDL_BlitSurface(imageSurface, NULL, windowSurface, NULL);
				SDL_UpdateWindowSurface(window);
				SDL_Delay(200000);
			}
		}
		SDL_DestroyWindow(window);
		SDL_Quit();

		return 0;
	}
}
