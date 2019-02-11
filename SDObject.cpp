#include "pch.h"

#include "SDObject.h"
#include "VecReal.h"
#include "CompositeLight.h"

SDObject::SDObject()
{
}

SDObject::SDObject(VecReal position, VecReal color, float r) {
	_position = position;
	_color = color;
	_r = r;
}


SDObject::~SDObject()
{
}

void SDObject::Draw(HDC hdc, CompositeLight* cl) {
	const int pmax = 255;

	for (int i = _position.x - _r; i <= _position.x + _r; i++) {
		for (int j = _position.y - _r; j <= _position.y + _r; j++) {
			if (Contains(i,j)) {

				VecReal normal = NormAt(i, j);
				float dot = cl->Dot(normal);
				// then this sphere is hit by light approaching from the exterior
				SetPixel(hdc, i, j, RGB(_color.x * pmax * dot, _color.y * pmax * dot, _color.z * pmax * dot));
				// SetPixel(hdc, i, j, RGB(_color.x * pmax * normal.x, _color.y * pmax * normal.y, _color.z * pmax * normal.z));
			}
		}
	}
}

bool SDObject::Contains(float i, float j) {
	return((i - _position.x) * (i - _position.x) + (j - _position.y) * (j - _position.y) < _r * _r);
}

VecReal SDObject::NormAt(float i, float j) {
	float x = (i - _position.x);
	float y = (j - _position.y);
	float z = _r - sqrt(x*x + y*y);

	VecReal direction = VecReal{ x, y, z, 1};
	direction.Normalize();

	// printf("%f,%f maps to %f,%f which maps to %f,%f,%f\n", i,j, x, y, direction.x, direction.y, direction.z);

	return(direction);
}