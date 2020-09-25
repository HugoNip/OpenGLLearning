#include <stdio.h>
#include <stdlib.h>

// Include GLEW. Always include it before gl.h and glfw3.h, since it's a bit magic
#include <GL/glew.h>

// include GLFW. We decided to let GLFW handle the window and the keyboard
#include <GLFW/glfw3.h>

// We don’t actually need this one right now, but this is a library for 3D mathematics. 
// It will prove very useful soon. There is no magic in GLM, you can write your own if you want; 
// it’s just handy. The “using namespace” is there to avoid typing “glm::vec3”, but “vec3” instead.
#include <glm/glm.hpp>
using namespace glm;


