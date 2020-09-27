# How to draw a textured cube

## About UV coordinates
When texturing a mesh, you need a way to tell to OpenGL which part of the image has to be used for each triangle. This is done with UV coordinates.

Each vertex can have, on top of its position, a couple of floats, U and V. These coordinates are used to access the texture, in the following way :

![UVintro.png](https://github.com/HugoNip/OpenGLLearning/blob/master/figures/UVintro.png)

Notice how the texture is distorted on the triangle.


## [Building on Linux](https://github.com/HugoNip/OpenGLLearning#building-on-linux)

## Output

![texturedcube.png](https://github.com/HugoNip/OpenGLLearning/blob/master/figures/texturedcube.png)

## Reference
**Tutorial** [Homepage](http://www.opengl-tutorial.org/beginners-tutorials/tutorial-5-a-textured-cube/)    
