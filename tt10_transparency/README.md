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

## Order matters !
The previous screenshot looks okay-ish, but that’s just because we’re lucky.

The problem
Here, I drew two squares with 50% alpha, one green and one red. You can see that order is important, the final colour gives an important clue to the eyes for proper depth perception.

![transparencyorder.png](https://github.com/HugoNip/OpenGLLearning/blob/master/figures/transparencyorder.png)



## The blend function
In order for the previous code to work, you need to setup your blend function.
```
// Enable blending
glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
```

Which means :

```
New color in framebuffer =
           current alpha in framebuffer * current color in framebuffer +
           (1 - current alpha in framebuffer) * shader's output color
```

Example from the image above, with red on top :
```
new color = 0.5*(0,1,0) + (1-0.5)*(1,0.5,0.5); // (the red was already blended with the white background)
new color = (1, 0.75, 0.25) = the same orange
```

## [Building on Linux](https://github.com/HugoNip/OpenGLLearning#building-on-linux)

## Output

![ref10.png](https://github.com/HugoNip/OpenGLLearning/blob/master/figures/ref10.png)

## Reference
**Tutorial** [Homepage](http://www.opengl-tutorial.org/intermediate-tutorials/tutorial-10-transparency/)    
