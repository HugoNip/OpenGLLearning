# How to do some basic shading

## Normals
### Triangle normals
The normal of a plane is a vector of length 1 that is perpendicular to this plane.

The normal of a triangle is a vector of length 1 that is perpendicular to this triangle. It is easily computed by taking the cross product of two of its edges (the cross product of a and b produces a vector that is perpendicular to both a and b, remember ?), and normalized : its length is brought back to 1. In pseudo-code :
```
triangle ( v1, v2, v3 )
edge1 = v2-v1
edge2 = v3-v1
triangle.normal = cross(edge1, edge2).normalize()
```

Don’t mix up normal and normalize(). Normalize() divides a vector (any vector, not necessarily a normal) by its length so that its new length is 1. normal is just the name for some vectors that happen to represent, well, a normal.

### Vertex normals
By extension, we call the normal of a vertex the combination of the normals of the surroundings triangles. This is handy because in vertex shaders, we deal with vertices, not triangles, so it’s better to have information on the vertex. And any way, we can’t have information on triangles in OpenGL. In pseudo-code :
```
vertex v1, v2, v3, ....
triangle tr1, tr2, tr3 // all share vertex v1
v1.normal = normalize( tr1.normal + tr2.normal + tr3.normal )
```

### Using vertex normals in OpenGL
To use normals in OpenGL, it’s very easy. A normal is an attribute of a vertex, just like its position, its color, its UV coordinates… so just do the usual stuff. Our loadOBJ function from [Tutorial 7](https://github.com/HugoNip/OpenGLLearning/tree/master/tt07_model_loading) already reads them from the OBJ file.
```
GLuint normalbuffer;
glGenBuffers(1, &normalbuffer);
glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), &normals[0], GL_STATIC_DRAW);
```
and
```
// 3rd attribute buffer : normals
glEnableVertexAttribArray(2);
glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
glVertexAttribPointer(
    2,                                // attribute
    3,                                // size
    GL_FLOAT,                         // type
    GL_FALSE,                         // normalized?
    0,                                // stride
    (void*)0                          // array buffer offset
);
```
and this is enough to get us started.


## [Building on Linux](https://github.com/HugoNip/OpenGLLearning#building-on-linux)

## Output

![ref07.png](https://github.com/HugoNip/OpenGLLearning/blob/master/figures/ref07.png)

## Reference
**Tutorial** [Homepage](http://www.opengl-tutorial.org/beginners-tutorials/tutorial-8-basic-shading/)    
