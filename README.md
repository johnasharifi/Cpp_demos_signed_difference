# Cpp_demos_signed_difference
Raytracing and signed difference engine

# Introduction
Using equations like 

<a href="https://www.codecogs.com/eqnedit.php?latex=b(x,y,z)&space;=&space;x^2&space;&plus;&space;y^2&space;&plus;&space;z^2&space;<&space;r^2" target="_blank"><img src="https://latex.codecogs.com/gif.latex?b(x,y,z)&space;=&space;x^2&space;&plus;&space;y^2&space;&plus;&space;z^2&space;<&space;r^2" title="b(x,y,z) = x^2 + y^2 + z^2 < r^2" /></a>

we can define 3D objects. These objects will always be as high-resolution as the display allows to be displayed; there are no meshes or polygons. 

This repository tracks my progress in building a 3D rendering engine which uses pure math, rather than meshes and polygons. While I could clone someone else's project and have a far superior solution, my objective in this project is to learn through implementation.

# Sprint 2 - most recent, 03/03/2019

The results of sprint 2 are below:
* Instead of writing directly into pixel space, we now follow the process: 
  * from world coordinates, 
  * change into camera-offset coordinates, 
  * then transform into pixel coordinates with 

* <a href="https://www.codecogs.com/eqnedit.php?latex=clip_x&space;=&space;winDim1&space;/&space;2&space;&plus;&space;dp.x&space;*&space;fov&space;/&space;dp.z;" target="_blank"><img src="https://latex.codecogs.com/gif.latex?clip_x&space;=&space;winDim1&space;/&space;2&space;&plus;&space;dp.x&space;*&space;fov&space;/&space;dp.z;" title="clip_x = winDim1 / 2 + dp.x * fov / dp.z;" /></a>
* <a href="https://www.codecogs.com/eqnedit.php?latex=clip_y&space;=&space;winDim2&space;/&space;2&space;&plus;&space;dp.y&space;*&space;fov&space;/&space;dp.z;" target="_blank"><img src="https://latex.codecogs.com/gif.latex?clip_y&space;=&space;winDim2&space;/&space;2&space;&plus;&space;dp.y&space;*&space;fov&space;/&space;dp.z;" title="clip_y = winDim2 / 2 + dp.y * fov / dp.z;" /></a>

<img src="https://github.com/johnasharifi/Cpp_demos_signed_difference/blob/master/image_3_zbuffer.png" width="48">
<img src="https://github.com/johnasharifi/Cpp_demos_signed_difference/blob/master/image_2_perspective.png" width="48">

# Sprint 1 - building the basics

* Rotatable light, with pitch and yaw converted to directionality
* Multiple SDSpheres with varying radii and positions
* Shading and normal calculation

<img src="https://github.com/johnasharifi/Cpp_demos_signed_difference/blob/master/image_1_shading.png" width="48">

# To do

* Light reflection off of objects onto other objects
* Introduce support for object surface textures and details
* Very long term, the objective is to build a tool that can take meshes and use the Finite Approximation Theorem to produce a parameterized mathematical expression of the object's volume. This will allow us to use infinite-definition rendering techniques to draw 3D models
