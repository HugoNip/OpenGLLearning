# OpenGL Learning
## Introduction
OpenGL (Open Graphics Library) is a cross-language, cross-platform application programming interface (API) for rendering 2D and 3D vector graphics. The API is typically used to interact with a graphics processing unit (GPU), to achieve hardware-accelerated rendering.

## Building on Linux
They are so many Linux variants out there that it’s impossible to list every possible platform. Adapt if required, and don’t hesitate to read your distribution’s documentation.

* Install the latest drivers. We highly recommend the closed-source binary drivers. It’s not GNU or whatever, but they work. If your distribution doesn’t provide an automatic install, try Ubuntu’s guide.

* Install all needed compilers, tools & libs. Complete list is : cmake make g++ libx11-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxrandr-dev libxext-dev libxcursor-dev libxinerama-dev libxi-dev . Use ```sudo apt-get install *****``` or ```su && yum install ******```.

* [Download the source code](http://www.opengl-tutorial.org/download/) and unzip it, for instance in ~/Projects/OpenGLLearning/

```
$ cd ~/Projects/OpenGLLearning/
$ mkdir build
$ cd build
$ cmake ..      // A makefile has been created in the build/ directory

$ make all      // Every tutorial and dependency will be compiled. Each executable will also be copied back into ~/Projects/OpenGLLearning/build/ directory

$ cd ~/Projects/OpenGLLearning/tt01_first_window // or cd ~/Projects/OpenGLLearning/build
$ ./exett01  // A blue window should appear.
``` 

## Tutorials
[Tutorial 0: Installing OpenGL](http://www.codebind.com/linux-tutorials/install-opengl-ubuntu-linux/)    
[Tutorial 1: Opening a window](http://www.opengl-tutorial.org/beginners-tutorials/tutorial-1-opening-a-window/)    
