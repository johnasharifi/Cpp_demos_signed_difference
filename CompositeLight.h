#pragma once

#include <vector>
#include "VecReal.h"

class CompositeLight
{
public:
	CompositeLight();
	CompositeLight(float, float, float);
	~CompositeLight();

	float Dot(VecReal);
private:
	std::vector<VecReal> data;
	VecReal _direction;
};