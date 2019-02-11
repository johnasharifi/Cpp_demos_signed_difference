#pragma once
struct VecReal
{
	float x, y, z, w;
	void Normalize();
	void Normalize(float intensity);
	float Mag();
};

