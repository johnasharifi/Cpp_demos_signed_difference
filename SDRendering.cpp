// SDRendering.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

const float PI = 3.14f;
const int winDim1 = 800;
const int winDim2 = 640;
const int pixMax = 255;

void DrawSceneData(HDC mydc, CompositeLight* light, std::list<SDObject>* scene_objects, float* zbuffer) {
	for (std::list<SDObject>::iterator sdo = scene_objects->begin(); sdo != scene_objects->end(); sdo++) {
		sdo->Draw(mydc, light, zbuffer);
	}
}

int main()
{
	HWND myconsole = GetConsoleWindow(); //Get a console handle
	HDC mydc = GetDC(myconsole); //Get a handle to device context
	MoveWindow(myconsole, 0, 0, SDRendering::winDim1, SDRendering::winDim2, true);
	CompositeLight* light = new CompositeLight(270.0f, 30.0f, 0.05f);
	float* zbuffer = new float[winDim1 * winDim2];
	for (int i = 0; i < winDim1 * winDim2; i++)
		zbuffer[i] = 0.0f;

	std::list<SDObject>* scene_objects = new std::list<SDObject>;

	scene_objects->push_back(SDObject(VecReal{ -10.0f, 0.0f, 3.0f, 0.0f }, VecReal{ 0.1f, 0.5f, 1.0f, 0.1f }, 15));
	scene_objects->push_back(SDObject(VecReal{ -05.0f, 0.0f, 3.0f, 0.0f }, VecReal{ 0.2f, 0.4f, 1.0f, 0.2f }, 15));
	scene_objects->push_back(SDObject(VecReal{ +00.0f, 0.0f, 3.0f, 0.0f }, VecReal{ 0.3f, 0.3f, 1.0f, 0.3f }, 15));
	scene_objects->push_back(SDObject(VecReal{ +05.0f, 0.0f, 3.0f, 0.0f }, VecReal{ 0.4f, 0.2f, 1.0f, 0.2f }, 15));
	scene_objects->push_back(SDObject(VecReal{ +10.0f, 0.0f, 3.0f, 0.0f }, VecReal{ 0.5f, 0.1f, 1.0f, 0.1f }, 15));

	DrawSceneData(mydc, light, scene_objects, zbuffer);

	delete light;
	scene_objects->clear();

	getchar();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
