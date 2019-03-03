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

float VecReal::SumPI(VecReal v)
{
	return(x * v.x + y * v.y + z * v.z);
}

float VecReal::Mag() {
	return(sqrt(x*x + y*y + z*z));
}

VecReal VecReal::operator-(VecReal v)
{
	return VecReal{ x - v.x, y - v.y, z - v.z, w - v.w};
}

VecReal VecReal::operator+(VecReal v)
{
	return VecReal{ v.x + x, v.y + y, v.z + z, v.w + w };
}

VecReal VecReal::operator*(float f)
{
	return VecReal{ x * f, y * f, z * f, w * f};
}

VecReal VecReal::operator*(VecReal v)
{
	return VecReal{ v.x * x, v.y * y, v.z * z, v.w * w };
}
