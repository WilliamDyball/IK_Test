#pragma once
#include <iostream>
#include <SDL.h>
#include <Eigen/Dense>
#include "Limb.h"

using namespace Eigen;

class AppWindow
{
	bool newTargetPos;
	int selectedBone;
	SDL_Window* window;
	Limb* limb;

public:
	Vector2d targetPos;
	SDL_Renderer* renderer;


	AppWindow(int width = 640, int height = 480);
	~AppWindow();

	void SetWindowSize(int width = 640, int height = 480);
	void DrawWindow();
	void UpdateTarget(int x, int y);
	void Loop();
};

