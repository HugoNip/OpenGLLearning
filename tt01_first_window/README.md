# Tutorial 1 : Opening a window

## Building on Linux
They are so many Linux variants out there that it’s impossible to list every possible platform. Adapt if required, and don’t hesitate to read your distribution’s documentation.

* Install the latest drivers. We highly recommend the closed-source binary drivers. It’s not GNU or whatever, but they work. If your distribution doesn’t provide an automatic install, try Ubuntu’s guide.

* Install all needed compilers, tools & libs. Complete list is : cmake make g++ libx11-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxrandr-dev libxext-dev libxcursor-dev libxinerama-dev libxi-dev . Use ```sudo apt-get install *****``` or ```su && yum install ******```.

* [Download the source code](http://www.opengl-tutorial.org/download/) and unzip it, for instance in ~/Projects/OpenGLTutorials/

```
$ cd ~/Projects/OpenGLTutorials/
$ mkdir build
$ cd build
$ cmake ..      // A makefile has been created in the build/ directory

$ make all      // Every tutorial and dependency will be compiled. Each executable will also be copied back into ~/Projects/OpenGLTutorials/

$ ./playground  // Open ~/Projects/OpenGLTutorials/playground, and launch . A black window should appear.
```

Note that you really should use an IDE like [Qt Creator](https://www.qt.io/developers). In particular, this one has built-in support for CMake, and it will provide a much nicer experience when debugging. Here are the instructions for QtCreator :

* In QtCreator, go to ```File->Tools->Options->Compile&Execute->CMake```    
* Set the path to *CMake*. This is most probably ```/usr/bin/cmake```    
* ```File->Open Project```; Select ```tutorials/CMakeLists.txt```    
* Select a ```build directory```, preferably outside the tutorials folder   
* Optionally set ```-DCMAKE_BUILD_TYPE=Debug``` in the parameters box. Validate.   
* Click on the hammer on the bottom. The tutorials can now be launched from the ```tutorials/``` folder.    
* To run the tutorials from QtCreator, click on ```Projects->Execution parameters->Working Directory```, and select the directory where the shaders, textures & models live. Example for tutorial 2 : ```~/opengl-tutorial/tutorial02_red_triangle/```     

## Reference
**Tutorial** [Homepage](http://www.opengl-tutorial.org/beginners-tutorials/tutorial-1-opening-a-window/)   
**GLFW** [Source](https://github.com/HugoNip/OpenGLLearning/tree/master/external/glfw-3.1.2), [Homepage](https://www.glfw.org/), [Compile](https://www.glfw.org/docs/latest/compile.html)    
**OpenGL Mathematics (GLM)** [Source](https://github.com/HugoNip/OpenGLLearning/tree/master/external/glm-0.9.7.1), [Homepage](https://glm.g-truc.net/0.9.9/index.html)    