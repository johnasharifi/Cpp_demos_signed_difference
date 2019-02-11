# Cpp_demos_signed_difference
Raytracing and signed difference engine

# Introduction
Using mathematical equations like 

<a href="https://www.codecogs.com/eqnedit.php?latex=b(x,y,z)&space;=&space;x^2&space;&plus;&space;y^2&space;&plus;&space;z^2&space;<&space;r^2" target="_blank"><img src="https://latex.codecogs.com/gif.latex?b(x,y,z)&space;=&space;x^2&space;&plus;&space;y^2&space;&plus;&space;z^2&space;<&space;r^2" title="b(x,y,z) = x^2 + y^2 + z^2 < r^2" /></a>

we can define 3D objects. These objects will always be as high-resolution as the display allows to be displayed; there are no meshes or polygons.

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
