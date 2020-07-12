#include "Limb.h"
#include <math.h>

Limb::Limb(SDL_Renderer* renderer)
{
	this->renderer = renderer;
}

Limb::~Limb()
{
	for (Bone* bone : bones) {
		delete bone;
	}
}

void Limb::AddBone(float length, int x, int y)
{
	if (bones.size() == 0) {
		Bone* bone = new Bone(x, y, 0, length, 0);
		bones.push_back(bone);
	}
	else {

	}
}

void Limb::AddBone(float length)
{
	if (bones.size() > 0) {
		int currentParent = bones.size() - 1;
		Vector2d temp = bones[currentParent]->GetEnd();
		Bone* bone = new Bone(temp.x(), temp.y(), 0, length, currentParent);
		bones.push_back(bone);
	}
	else {

	}
}

void Limb::MoveToTarget(Vector2d& _target, int selectedBone)
{
	bones[selectedBone]->PointAt(_target);
	bones[selectedBone]->Move(_target);
	selectedBone--;
	if (selectedBone < 0) {
		return;
	}
	MoveToTarget(bones[selectedBone + 1]->start, selectedBone);
}

void Limb::Update()
{
}

void Limb::Draw()
{
	Update();
	for (Bone* bone : bones) {
		SDL_SetRenderDrawColor(renderer, 5 * bone->hierarchyID, 255, 200, 255);
		Vector2d temp = bone->GetEnd();
		SDL_RenderDrawLine(renderer, bone->start.x(), bone->start.y(), temp.x(), temp.y());
	}
}
