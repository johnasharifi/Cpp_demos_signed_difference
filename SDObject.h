#pragma once

#include "VecReal.h"

class SDObject
{
private:
	VecReal NormAt(float, float);
	bool Contains(float, float);
	VecReal NormAt(float, float, float);
public:
	SDObject();
	SDObject(VecReal, VecReal, float);
	~SDObject();
	void Draw(HDC hdc, CompositeLight * cl, float*);
	bool Contains(float, float, float);
	VecReal _position;
	VecReal _color;
	float _r;
};

