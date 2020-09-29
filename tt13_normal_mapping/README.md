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

 
## Tangent and Bitangent (Tangent Space)

***Tangent Space is used to associate Texture(UV) Space to Model[X, Y, Z] Space***.

To define the tangent space, we need 3 vectors: Normal (blue), Tangent and Bitangent vectors.

![NTBFromUVs.png](https://github.com/HugoNip/OpenGLLearning/blob/master/figures/NTBFromUVs.png)     

Here is the algorithm : if we note deltaPos1 and deltaPos2 two edges of our triangle, and deltaUV1 and deltaUV2 the corresponding differences in UVs: 

![deltaUV.png](https://github.com/HugoNip/OpenGLLearning/blob/master/figures/deltaUV.png)     

we can express our problem with the following equation :

```
deltaPos1 = deltaUV1.x * T + deltaUV1.y * B
deltaPos2 = deltaUV2.x * T + deltaUV2.y * B
```

Once we have our T, B, N vectors, we also have this nice matrix which enables us to go from Tangent Space to Model Space :

![TBN.png](https://github.com/HugoNip/OpenGLLearning/blob/master/figures/TBN.png)     

**With this TBN matrix, we can transform normals (extracted from the texture) into model space**. However, it’s usually done the other way around : transform everything from Model Space to Tangent Space, and keep the extracted normal as-is. All computations are done in Tangent Space, which doesn’t changes anything.

Do have this inverse transformation, we simply have to take the matrix inverse, which in this case (an orthogonal matrix, i.e each vector is perpendicular to the others. See “going further” below) is also its transpose, much cheaper to compute :

```
invTBN = transpose(TBN)
```
![transposeTBN.png](https://github.com/HugoNip/OpenGLLearning/blob/master/figures/transposeTBN.png)    



## [Building on Linux](https://github.com/HugoNip/OpenGLLearning#building-on-linux)

## Output

![clock.PNG](https://github.com/HugoNip/OpenGLLearning/blob/master/figures/clock.PNG)

## Reference
[**Tutorial 1 (OpenGL)**](http://www.opengl-tutorial.org/intermediate-tutorials/tutorial-13-normal-mapping/)    
[**Toturial 2**](https://www.cnblogs.com/freeblues/p/5742956.html)    
[**Toturial 3**](https://www.cnblogs.com/wangchengfeng/p/3470310.html)    
[**Toturial 4**](https://blog.csdn.net/bonchoix/article/details/8619624)    