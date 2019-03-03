#pragma once
struct VecReal
{
	float x, y, z, w;
	void Normalize();
	void Normalize(float intensity);
	float SumPI(VecReal);
	float Mag();
	VecReal operator -(VecReal);
	VecReal operator +(VecReal);
	VecReal operator *(float);
	VecReal operator *(VecReal);
	float Dot(VecReal);
};

