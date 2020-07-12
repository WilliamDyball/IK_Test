#pragma once
#include <vector>
#include <SDL.h>
#include "Bone.h"

class Limb
{
	SDL_Renderer* renderer;
public:
	//The bones that make up the limb.
	std::vector<Bone*> bones;

	Vector2d effector;

	Limb(SDL_Renderer* _renderer);
	~Limb();

	void AddBone(float legnth, int x, int y);
	void AddBone(float legnth);
	void MoveToTarget(Vector2d& _target, int selectedBone);
	void Update();
	void Draw();
};

