# Intall OpenGL
Run the following commands to install OpenGL.
```
$ sudo apt-get update
$ sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev
```

Now to test if OpenGl libraries are working fine on our Linux, we will create a C++ program and test it.    
Now give the command below to compile the code.    
```
$ g++ main.cpp -o firstOpenGlApp -lglut -lGLU -lGL
```

Now run the OpenGl program with following command     
```
$ ./firstOpenGlApp
```
# Tutorials
[Intall OpenGL](http://www.codebind.com/linux-tutorials/install-opengl-ubuntu-linux/)    
