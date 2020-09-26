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
This model is defined by a set of vertices. The X,Y,Z coordinates of these vertices are defined relative to the object’s center : that is, if a vertex is at (0,0,0), it is at the **center of the object**.

![model.png](https://github.com/HugoNip/OpenGLLearning/blob/master/figures/model.png)

We’d like to be able to move this model, maybe because the player controls it with the keyboard and the mouse. Easy, you just learnt to do so : ```translation*rotation*scale```, and done. You apply this matrix to all your vertices at each frame (in GLSL, not in C++!) and everything moves. Something that doesn’t move will be at the *center of the world*.

![world.png](https://github.com/HugoNip/OpenGLLearning/blob/master/figures/world.png)

Your vertices are now in **World Space**. This is the meaning of the black arrow in the image below : We went from **Model Space** (all vertices defined relatively to the center of the model) to **World Space** (all vertices defined relatively to the center of the world).

![model_to_world.png](https://github.com/HugoNip/OpenGLLearning/blob/master/figures/model_to_world.png)

We can sum this up with the following diagram :

![M.png](https://github.com/HugoNip/OpenGLLearning/blob/master/figures/M.png)



### The View matrix

Let’s quote Futurama again :
```
The engines don’t move the ship at all. The ship stays where it is and the engines move the universe around it.
```

![camera.png](https://github.com/HugoNip/OpenGLLearning/blob/master/figures/camera.png)

When you think about it, the same applies to cameras. If you want to view a moutain from another angle, you can either **move the camera** or **move the mountai**n. While not practical in real life, this is really simple and handy in Computer Graphics.

So initially your camera is at the origin of the World Space. In order to move the world, you simply introduce another matrix. Let’s say you want to move your camera of **3 units to the right (+X)**. This is equivalent to moving your whole world (meshes included) **3 units to the LEFT** ! (-X). While you brain melts, let’s do it :

```
// Use #include <glm/gtc/matrix_transform.hpp> and #include <glm/gtx/transform.hpp>
glm::mat4 ViewMatrix = glm::translate(glm::mat4(), glm::vec3(-3.0f, 0.0f ,0.0f));
```

Again, the image below illustrates this : We went from **World Space** (all vertices defined relatively to the center of the world, as we made so in the previous section) to **Camera Space** (all vertices defined relatively to the camera).

![model_to_world_to_camera.png](https://github.com/HugoNip/OpenGLLearning/blob/master/figures/model_to_world_to_camera.png)

Before you head explodes from this, enjoy GLM’s great glm::lookAt function:

```
glm::mat4 CameraMatrix = glm::lookAt(
    cameraPosition, // the position of your camera, in world space
    cameraTarget,   // where you want to look at, in world space
    upVector        // probably glm::vec3(0,1,0), but (0,-1,0) would make you looking upside-down, which can be great too
);
```

Here’s the compulsory diagram :

![MV.png](https://github.com/HugoNip/OpenGLLearning/blob/master/figures/MV.png)



### The Projection matrix

We’re now in Camera Space. This means that after all theses transformations, **a vertex** that happens to have x==0 and y==0 **should be rendered at the center of the screen**. But we can’t use only the x and y coordinates to determine where an object should be put on the screen : its distance to the camera (z) counts, too ! For two vertices with similar x and y coordinates, the vertex with the biggest z coordinate will be more on the center of the screen than the other.

This is called a perspective projection :

![model_to_world_to_camera_to_homogeneous.png](https://github.com/HugoNip/OpenGLLearning/blob/master/figures/model_to_world_to_camera_to_homogeneous.png)

And luckily for us, a 4x4 matrix can represent this projection1 :

```
// Generates a really hard-to-read matrix, but a normal, standard 4x4 matrix nonetheless
glm::mat4 projectionMatrix = glm::perspective(
    glm::radians(FoV), // The vertical Field of View, in radians: the amount of "zoom". Think "camera lens". Usually between 90° (extra wide) and 30° (quite zoomed in)
    4.0f / 3.0f,       // Aspect Ratio. Depends on the size of your window. Notice that 4/3 == 800/600 == 1280/960, sounds familiar ?
    0.1f,              // Near clipping plane. Keep as big as possible, or you'll get precision issues.
    100.0f             // Far clipping plane. Keep as little as possible.
);
```

We went from **Camera Space** (all vertices defined relatively to the camera) to **Homogeneous Space** (all vertices defined in a small cube. ***Everything inside the cube is onscreen***).

And the final diagram :

![MVP.png](https://github.com/HugoNip/OpenGLLearning/blob/master/figures/MVP.png)

### How to understand MVP?

Here’s another diagram so that you understand better what happens with this Projection stuff. Before projection, we’ve got our blue objects, in **Camera Space**, and the **red shape** represents the **frustum of the camera** : the part of the scene that the camera is actually able to see.

![nondeforme.png](https://github.com/HugoNip/OpenGLLearning/blob/master/figures/nondeforme.png)

Multiplying everything by the **Projection Matrix** has the following effect :

![homogeneous.png](https://github.com/HugoNip/OpenGLLearning/blob/master/figures/homogeneous.png)

In this image, the **frustum is now a perfect cube** (between -1 and 1 on all axes, it’s a little bit hard to see it), and **all blue objects have been deformed** in the same way. Thus, the objects that are near the camera ( = near the face of the cube that we can’t see) are big, the others are smaller. Seems like real life !

Let’s see what it looks like from the “behind” the frustum :

![projected.png](https://github.com/HugoNip/OpenGLLearning/blob/master/figures/projected.png)

Here you get your image ! It’s just a little bit too square, so another mathematical transformation is applied (this one is automatic, you don’t have to do it yourself in the shader) to fit this to the actual window size :

![final.PNG](https://github.com/HugoNip/OpenGLLearning/blob/master/figures/final.PNG)

And this is the image that is actually rendered !


## Reference
**Tutorial** [Homepage](http://www.opengl-tutorial.org/beginners-tutorials/tutorial-3-matrices/)    
