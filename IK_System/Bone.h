#pragma once
#include <Eigen/Dense>

using namespace Eigen;

class Bone
{
public:
	int hierarchyID;
	Vector2d start;
	double length;
	double angle;

	Bone(int x, int y, float angle, float length, int hierarchyID = -1);
	~Bone();

	void PointAt(Vector2d _target);
	void Move(Vector2d _target);
	Vector2d GetEnd();
};

