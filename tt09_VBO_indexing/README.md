# How to do some basic shading

## The principle of indexing
Until now, when building your VBO, we always duplicated our vertices whenever two triangles shared an edge.

In this tutorial, we introduce indexing, which enables to reuse the same vertex over and over again. This is done with an **index buffer**.

![indexing.png](https://github.com/HugoNip/OpenGLLearning/blob/master/figures/indexing.png)

The index buffer contains integers, three for each triangle in the mesh, which reference the various **attribute buffers** (position, colour, UV coordinates, other UV coordinates, normal, ...). It’s a little bit like in the OBJ file format, with one huge difference : *there is only ONE index buffer*. This means that for a vertex to be shared between two triangles, all attributes must be the same.




## [Building on Linux](https://github.com/HugoNip/OpenGLLearning#building-on-linux)

## Output

![indexing.png](https://github.com/HugoNip/OpenGLLearning/blob/master/figures/indexing.png)

## Reference
**Tutorial** [Homepage](http://www.opengl-tutorial.org/intermediate-tutorials/tutorial-9-vbo-indexing/)    
