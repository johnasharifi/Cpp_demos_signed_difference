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

void SDObject::Draw(HDC hdc, CompositeLight* cl, float* zbuffer) {
	const int pmax = 255;

	VecReal dp = _position - VecReal{0,0,0,1};
	if (dp.Mag() == 0) {
		printf("Error: zero-distance vector to camera");
		return;
	}

	int fov = SDRendering::fov;
	int fov2 = SDRendering::fov / 4;

	float local_r = _r * fov2 / dp.z;
		
	// map from world xyz to pixel i,j
	float clip_x = SDRendering::winDim1 / 2 + dp.x * fov / dp.z;
	float clip_y = SDRendering::winDim2 / 2 + dp.y * fov / dp.z;

	for (int i = (int)(clip_x - local_r); i < clip_x + local_r; i++) {
		for (int j = (int)(clip_y - local_r); j < clip_y + local_r; j++) {

			float local_pixel_x = (i - clip_x) / local_r;
			float local_pixel_y = (j - clip_y) / local_r;
			float local_pixel_z = 1 - sqrt(local_pixel_x * local_pixel_x + local_pixel_y * local_pixel_y);

			int zbuffer_index = i * SDRendering::winDim1 + j;
			bool zbuffer_is_writable = (zbuffer_index >= 0 && zbuffer_index < SDRendering::winDim1 * SDRendering::winDim2) && (zbuffer[zbuffer_index] < local_pixel_z);

			if (Contains(local_pixel_x, local_pixel_y, local_r) && zbuffer_is_writable) {
				zbuffer[zbuffer_index] = local_pixel_z;
				float dot = cl->Dot(VecReal{local_pixel_x, local_pixel_y, local_pixel_z, 1.0f});
					
				SetPixel(hdc, i, j, RGB(_color.x * pmax * dot, _color.y * pmax * dot, _color.z * pmax * dot));
			}

		}
	}
}

bool SDObject::Contains(float i, float j, float local_r) {
	return(i * i + j * j < 1);
}

bool SDObject::Contains(float i, float j) {
	return((i - _position.x) * (i - _position.x) + (j - _position.y) * (j - _position.y) < _r * _r);
}

VecReal SDObject::NormAt(float i, float j, float local_r) {
	float world_z = local_r - sqrt((i / local_r)*(i / local_r) + (j / local_r)*(j / local_r));
	VecReal direction = VecReal{i, j, world_z, 1 };
	direction.Normalize();
	// printf("%f,%f transformed into %f,%f,%f\n", i, j, direction.x, direction.y, direction.z);

	return(direction);
}

VecReal SDObject::NormAt(float i, float j) {
	float x = (i - _position.x);
	float y = (j - _position.y);
	float z = _r - sqrt(x*x + y*y);

	VecReal direction = VecReal{ x, y, z, 1};
	direction.Normalize();

	return(direction);
}