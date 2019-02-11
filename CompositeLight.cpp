#include "pch.h"
#include "CompositeLight.h"
#include "VecReal.h"
#include <cmath>

CompositeLight::CompositeLight()
{
}

CompositeLight::CompositeLight(float yaw, float pitch, float min_light) {
	const float PI_RAD = 3.14f / 180.0f;
	float x = cos(yaw * PI_RAD) * cos(pitch * PI_RAD);
	float y = sin(yaw * PI_RAD) * cos(pitch * PI_RAD);
	float z = sin(pitch * PI_RAD);
	_direction = VecReal{ x, y, z, min_light };
	_direction.Normalize();
}

CompositeLight::~CompositeLight()
{
}

float CompositeLight::Dot(VecReal normal)
{
	float sum = (normal.x * _direction.x + normal.y * _direction.y + normal.z * _direction.z) / _direction.Mag();
	// printf("dot of %f,%f,%f with %f,%f,%f is %f\n", normal.x, normal.y, normal.z, _direction.x, _direction.y, _direction.z, sum);

	if (sum < _direction.w) {
		sum = _direction.w;
	}

	if (sum > 1) sum = 1;

	// return normal.w + (1 - normal.w) * sum;
	return(sum);
}