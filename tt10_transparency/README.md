# How to do some basic shading

## The alpha channel
The concept of the alpha channel is pretty simple. Instead of a writing an RGB result, you write an RGBA :
```
// Ouput data : it's now a vec4
out vec4 color;
```

the first 3 components are still accessed with the .xyz swizzle operator, while the last one is accessed with .a :
```
color.a = 0.3;
```

Unintuitively, alpha = opaqueness, so alpha = 1 means fully opaque while alpha = 0 means fully transparent.




## [Building on Linux](https://github.com/HugoNip/OpenGLLearning#building-on-linux)

## Output

![ref09.png](https://github.com/HugoNip/OpenGLLearning/blob/master/figures/ref09.png)

## Reference
**Tutorial** [Homepage](http://www.opengl-tutorial.org/intermediate-tutorials/tutorial-10-transparency/)    
