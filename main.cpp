#define SDL_ENABLE_OLE_NAMES
#define _USE_MATH_DEFINES

#include "SDL3/SDL.h"
#include "SDL3/SDL_main.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

#pragma comment(lib, "SDL3")

//c++ console entry -> IOS, Window, Linux
//int main(int argc, char* argv[])
//{
//	
//}

int SDL_main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	SDL_Window* MyWindow = SDL_CreateWindow("Game", 640, 480, SDL_WINDOW_OPENGL);

	SDL_Renderer* MyRenderer = SDL_CreateRenderer(MyWindow, nullptr);

	SDL_Event MyEvent;

	srand((unsigned int)time(NULL));
	int RGB = std::rand() % 256;

	bool bIsRunning = true;
	while (bIsRunning)
	{
		if (SDL_PollEvent(&MyEvent))
		{
			if (MyEvent.type == SDL_EVENT_QUIT)
			{
				bIsRunning = false;
			}
		}

		else
		{
			SDL_SetRenderDrawColor(MyRenderer, 255, 255, 255, 255);
			SDL_RenderClear(MyRenderer);

			for (int j = 0; j < 100; ++j)
			{
				SDL_SetRenderDrawColor(MyRenderer, SDL_rand(255), SDL_rand(255), SDL_rand(255), 0);

				int Radius = 100;
				int CenterX = 320;
				int CenterY = 240;

				// 640X480 창 가운데에 반지름 100짜리 원 그리기
				for (int Degree = 10; Degree <= 360; Degree += 10)
				{
					int OLDX = SDL_cos((float)(Degree - 10) * SDL_PI_F / 180.0f) * Radius + CenterX;
					int OLDY = SDL_sin((float)(Degree - 10) * SDL_PI_F / 180.0f) * Radius + CenterY;

					int X = SDL_cos((float)Degree * SDL_PI_F / 180.0f) * Radius + CenterX;
					int Y = SDL_sin((float)Degree * SDL_PI_F / 180.0f) * Radius + CenterY;

					SDL_RenderLine(MyRenderer, OLDX, OLDY, X, Y);
				}
			}
			/*for (int i = 1; i <= 100; ++i)
			{
				SDL_SetRenderDrawColor(MyRenderer, SDL_rand(255), SDL_rand(255), SDL_rand(255), SDL_rand(255));
				SDL_FRect Rect{ SDL_rand(640), SDL_rand(480), SDL_rand(200) + 1, SDL_rand(200) + 1 };
				SDL_RenderFillRect(MyRenderer, &Rect);
				
			}*/

			SDL_RenderPresent(MyRenderer);
		}
	}

	SDL_DestroyRenderer(MyRenderer);

	SDL_DestroyWindow(MyWindow);

	SDL_Quit();
	return 0;
}
