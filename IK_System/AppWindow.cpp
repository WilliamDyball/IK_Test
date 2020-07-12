#include "AppWindow.h"

AppWindow::AppWindow(int width, int height)
{
	newTargetPos = false;
	selectedBone = 0;
	window = SDL_CreateWindow("IK_Test", 50, 50, width, height, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	limb = new Limb(renderer);
	limb->AddBone(50, width / 2, height / 2);
	limb->AddBone(40);
	limb->AddBone(40);
	limb->AddBone(40);
	limb->AddBone(40);
	limb->AddBone(40);
	limb->AddBone(40);
	limb->AddBone(40);
}

AppWindow::~AppWindow()
{
	delete limb;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void AppWindow::SetWindowSize(int width, int height)
{
	SDL_SetWindowSize(window, width, height);
}

void AppWindow::DrawWindow()
{
	SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255);
	SDL_RenderClear(renderer);

	limb->Draw();
}

void AppWindow::UpdateTarget(int x, int y)
{
	newTargetPos = true;
	targetPos << x, y;
}

void AppWindow::Loop()
{
	if (newTargetPos) {
		limb->MoveToTarget(this->targetPos, limb->bones.size() - 1);
		newTargetPos = false;
	}
	DrawWindow();

	SDL_RenderPresent(renderer);
	SDL_Delay(1);
}
