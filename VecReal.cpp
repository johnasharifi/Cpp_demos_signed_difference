#include "pch.h"
#include <cmath>

void VecReal::Normalize()
{
	float sum = Mag();
	x = x / sum;
	y = y / sum;
	z = z / sum;
}

void VecReal::Normalize(float sharpness) {
	x = (x > 0? 1:-1) * pow(abs(x), sharpness);
	y = (y > 0? 1:-1) * pow(abs(y), sharpness);
	z = (z > 0? 1:-1) * pow(abs(z), sharpness);
	
	Normalize();
}

float VecReal::Mag() {
	return(sqrt(x*x + y*y + z*z));
}