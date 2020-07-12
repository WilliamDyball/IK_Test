#define SDL_MAIN_HANDLED
#pragma once
#include "SDL.h"
#include <Eigen\Dense>
#include "AppWindow.h"
#include "Limb.h"
#include "Bone.h"
#include <iostream>
using namespace Eigen;

int main() {
	SDL_SetMainReady();
	SDL_Init(SDL_INIT_VIDEO);
	AppWindow window(640, 480);

	while (true)
	{
		SDL_Event e;
		if (SDL_PollEvent(&e)) {
			switch (e.type) {
			case SDL_MOUSEBUTTONDOWN:
				window.UpdateTarget((float)e.button.x, (float)e.button.y);
				break;
			}
		}
		window.Loop();
	}
	SDL_Quit();

	return 0;
}