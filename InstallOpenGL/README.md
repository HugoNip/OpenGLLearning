# Intall OpenGL
Run the following commands to install OpenGL.
```
$ sudo apt-get update
$ sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev
```
# Test OpenGl
Now to test if OpenGl libraries are working fine on Linux, we will create a C++ program and test it. 

## Compile
Now give the command below to compile the code.    
```
$ g++ main.cpp -o firstOpenGlApp -lglut -lGLU -lGL
```
## Run
Now run the OpenGl program with following command     
```
$ ./firstOpenGlApp
```
## Output
![opengl_out-300x247.png](https://github.com/HugoNip/OpenGLLearning/blob/master/figures/opengl_out-300x247.png)

# Tutorials
[Intall OpenGL](http://www.codebind.com/linux-tutorials/install-opengl-ubuntu-linux/)    
