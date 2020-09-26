# How to use matrices?

## [Guideline](http://www.opengl-tutorial.org/beginners-tutorials/tutorial-3-matrices/#transformation-matrices)
* Homogeneous coordinates
* Transformation matrices
    * An introduction to matrices
    * Translation matrices
    * The Identity matrix
    * Scaling matrices
    * Rotation matrices
    * Cumulating transformations
* The Model, View and Projection matrices
    * The Model matrix
    * The View matrix
    * The Projection matrix
    * Cumulating transformations : the ModelViewProjection matrix

## [Building on Linux](https://github.com/HugoNip/OpenGLLearning#building-on-linux)

## The Model, View and Projection (MVP) matrices
The Model, View and Projection matrices are a handy tool to separate transformations cleanly.

### The Model matrix
This model is defined by a set of vertices. The X,Y,Z coordinates of these vertices are defined relative to the object’s center : that is, if a vertex is at (0,0,0), it is at the center of the object.

![model.png](https://github.com/HugoNip/OpenGLLearning/blob/master/figures/model.png)

We’d like to be able to move this model, maybe because the player controls it with the keyboard and the mouse. Easy, you just learnt to do so : ```translation*rotation*scale```, and done. You apply this matrix to all your vertices at each frame (in GLSL, not in C++!) and everything moves. Something that doesn’t move will be at the *center of the world*.

![world.png](https://github.com/HugoNip/OpenGLLearning/blob/master/figures/world.png)

Your vertices are now in *World Space*. This is the meaning of the black arrow in the image below : We went from Model Space (all vertices defined relatively to the center of the model) to World Space (all vertices defined relatively to the center of the world).

![model_to_world.png](https://github.com/HugoNip/OpenGLLearning/blob/master/figures/model_to_world.png)

We can sum this up with the following diagram :

![M.png](https://github.com/HugoNip/OpenGLLearning/blob/master/figures/M.png)



### The View matrix




### The Projection matrix



## Reference
**Tutorial** [Homepage](http://www.opengl-tutorial.org/beginners-tutorials/tutorial-3-matrices/)    
