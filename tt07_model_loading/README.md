# How to load model (.obj file)

## Using the loaded data
Once we’ve got this, almost nothing changes. Instead of declaring our usual static const GLfloat g_vertex_buffer_data[] = {…}, you declare a std::vector vertices instead (same thing for UVS and normals). You call loadOBJ with the right parameters :

```
// Read our .obj file
std::vector< glm::vec3 > vertices;
std::vector< glm::vec2 > uvs;
std::vector< glm::vec3 > normals; // Won't be used at the moment.
bool res = loadOBJ("cube.obj", vertices, uvs, normals);
```

and give your vectors to OpenGL instead of your arrays :

```
glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);
```

And that’s it !

## [Building on Linux](https://github.com/HugoNip/OpenGLLearning#building-on-linux)

## Output

![ref07.png](https://github.com/HugoNip/OpenGLLearning/blob/master/figures/ref07.png)

## Reference
**Tutorial** [Homepage](http://www.opengl-tutorial.org/beginners-tutorials/tutorial-7-model-loading/)    
