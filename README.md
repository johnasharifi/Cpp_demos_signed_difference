# Cpp_demos_signed_difference
Raytracing and signed difference engine

# Introduction
Using mathematical equations like 

<a href="https://www.codecogs.com/eqnedit.php?latex=b(x,y,z)&space;=&space;x^2&space;&plus;&space;y^2&space;&plus;&space;z^2&space;<&space;r^2" target="_blank"><img src="https://latex.codecogs.com/gif.latex?b(x,y,z)&space;=&space;x^2&space;&plus;&space;y^2&space;&plus;&space;z^2&space;<&space;r^2" title="b(x,y,z) = x^2 + y^2 + z^2 < r^2" /></a>

we can define 3D objects. These objects will always be as high-resolution as the display allows to be displayed; there are no meshes or polygons. This repository tracks my progress in building a 3D rendering engine. 

I could just clone someone else's 3D rendering engine. I will not because my objective is to learn by implementing.

The results of sprint 2 are below:
* Instead of writing directly into pixel space, starting with world coordinates, changing to object-offset coordinates, then transforming to pixel coordinates with 

<a href="https://www.codecogs.com/eqnedit.php?latex=clip_x&space;=&space;winDim1&space;/&space;2&space;&plus;&space;dp.x&space;*&space;fov&space;/&space;dp.z;" target="_blank"><img src="https://latex.codecogs.com/gif.latex?clip_x&space;=&space;winDim1&space;/&space;2&space;&plus;&space;dp.x&space;*&space;fov&space;/&space;dp.z;" title="clip_x = winDim1 / 2 + dp.x * fov / dp.z;" /></a>

![Sprint 2](https://github.com/johnasharifi/Cpp_demos_signed_difference/blob/master/image_2_perspective.png)

The results of sprint 1 are below:
* Rotatable light, with pitch and yaw converted to directionality
* Multiple SDSpheres with varying radii and positions
* Shading and normal calculation

![Sprint 1](https://github.com/johnasharifi/Cpp_demos_signed_difference/blob/master/image_1_shading.png)

# To do

* Specular lighting, lighting sharpness
* Light reflection off of objects onto other objects
* Support for more objects than just spheres, e.g. cylinders
* Camera view matrix

Very long term, the objective is to convert a mesh into a parameterized signed difference equation using the Finite Approximation Theorem and knowledge of planes.
