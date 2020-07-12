#include "Bone.h"
#include <math.h>

Bone::Bone(int x, int y, float angle, float length, int hierarchyID)
{
	start << x, y;
	this->angle = angle;
	this->length = length;
	this->hierarchyID = hierarchyID;
}

Bone::~Bone() {}


void Bone::PointAt(Vector2d _target)
{
	float dx = _target.x() - this->start.x();
	float dy = _target.y() - this->start.y();

	this->angle = atan2(dy, dx);
}

void Bone::Move(Vector2d _target)
{
	this->PointAt(_target);
	this->start << _target.x() - cos(this->angle) * this->length, _target.y() - sin(this->angle) * this->length;
}

Vector2d Bone::GetEnd()
{
	return Vector2d(this->start.x() + cos(this->angle) * this->length, this->start.y() + sin(this->angle) * this->length);
}

