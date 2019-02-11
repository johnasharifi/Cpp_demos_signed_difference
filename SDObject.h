#pragma once

#include "VecReal.h"

class SDObject
{
private:
	VecReal NormAt(float, float);
	bool Contains(float, float);
public:
	SDObject();
	SDObject(VecReal, VecReal, float);
	~SDObject();
	void Draw(HDC, CompositeLight*);
	VecReal _position;
	VecReal _color;
	float _r;
};

