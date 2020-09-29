# How to do normal mapping (法线贴图)

## Normal textures
A “normal texture” looks like this :

![normal.jpg](https://github.com/HugoNip/OpenGLLearning/blob/master/figures/normal.jpg)

In each RGB texel is encoded a XYZ vector : each colour component is between 0 and 1, and each vector component is between -1 and 1, so this simple mapping goes from the texel to the normal :

```
normal = (2*color)-1 // on each component
```

The texture has a general blue tone because overall, the normal is towards the “**outside of the surface**”. As usual, X is right in the plane of the texture, Y is up (again in the plane of the texture), thus given the right hand rule Z point to the **“outside” of the plane of the texture**.

This texture is mapped just like the diffuse one; the big problem is how to convert our normal, which is expressed in the space each individual triangle (tangent space, also called image space), in model space (since this is what is used in our shading equation).

## [Building on Linux](https://github.com/HugoNip/OpenGLLearning#building-on-linux)

## Output

![clock.PNG](https://github.com/HugoNip/OpenGLLearning/blob/master/figures/clock.PNG)

## Reference
**OpenGL Tutorial** [Homepage](http://www.opengl-tutorial.org/intermediate-tutorials/tutorial-13-normal-mapping/)    
[**Toturial**](https://www.cnblogs.com/freeblues/p/5742956.html)    
