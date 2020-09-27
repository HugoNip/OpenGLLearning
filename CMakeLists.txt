# CMake entry point
cmake_minimum_required (VERSION 3.0)
project (Tutorials)

find_package(OpenGL REQUIRED)


if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
    message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like bin_Visual2012_64bits/)" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
	message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
	message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()



# Compile external dependencies 
add_subdirectory (external)

# On Visual 2005 and above, this module can set the debug working directory
cmake_policy(SET CMP0026 OLD)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/external/rpavlik-cmake-modules-fe2273")
include(CreateLaunchers)
include(MSVCMultipleProcessCompile) # /MP



if(INCLUDE_DISTRIB)
	add_subdirectory(distrib)
endif(INCLUDE_DISTRIB)

include_directories(
	external/AntTweakBar-1.16/include/
	external/glfw-3.1.2/include/
	external/glm-0.9.7.1/
	external/glew-1.13.0/include/
	external/assimp-3.0.1270/include/
	external/bullet-2.81-rev2613/src/
	.
)

set(ALL_LIBS
	${OPENGL_LIBRARY}
	glfw
	GLEW_1130
)

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

message("CMAKE_CURRENT_SOURCE_DIR: " ${CMAKE_CURRENT_SOURCE_DIR})
message("CMAKE_CURRENT_BINARY_DIR: " ${CMAKE_CURRENT_BINARY_DIR})
message("CMAKE_CFG_INTDIR: " ${CMAKE_CFG_INTDIR})
message("CMAKE_GENERATOR: " ${CMAKE_GENERATOR})

# Tutorial 1
add_executable(exett01 tt01_first_window/main.cpp)

target_link_libraries(exett01 ${ALL_LIBS})

# Xcode and Visual working directories
set_target_properties(exett01 PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/tt01_first_window/")
create_target_launcher(exett01 WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/tt01_first_window/")


# Tutorial 2
add_executable(exett02 tt02_red_triangle/main.cpp 
						common/shader.cpp	
						common/shader.hpp
						tt02_red_triangle/SimpleFragmentShader.fragmentshader
						tt02_red_triangle/SimpleVertexShader.vertexshader)

target_link_libraries(exett02 ${ALL_LIBS})

# Xcode and Visual working directories
set_target_properties(exett02 PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/tt02_red_triangle/")
create_target_launcher(exett02 WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/tt02_red_triangle/")
create_default_target_launcher(exett02 WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/tt02_red_triangle/") # tut 1 is not the default or people would complain that tut 2 doesn't work


# Tutorial 3
add_executable(exett03 tt03_matrices/main.cpp
						common/shader.cpp
						common/shader.hpp

						tt03_matrices/SimpleTransform.vertexshader
						tt03_matrices/SingleColor.fragmentshader)

#set_target_properties(exett03 PROPERTIES RUNTIME_OUTPUT_DIRECTORY /test1)
target_link_libraries(exett03 ${ALL_LIBS})

# Xcode and Visual working directories
set_target_properties(exett03 PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/tt03_matrices/")
create_target_launcher(exett03 WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/tt03_matrices/") # Visual


# Tutorial 4
add_executable(exett04 tt04_colored_cube/main.cpp
						common/shader.cpp
						common/shader.hpp
						
						tt04_colored_cube/TransformVertexShader.vertexshader
						tt04_colored_cube/ColorFragmentShader.fragmentshader
)
target_link_libraries(exett04 ${ALL_LIBS})

# Xcode and Visual working directories
set_target_properties(exett04 PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/tt04_colored_cube/")
create_target_launcher(exett04 WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/tt04_colored_cube/")


# Tutorial 5
add_executable(exett05 tt05_textured_cube/main.cpp
						common/shader.cpp
						common/shader.hpp
						common/texture.cpp
						common/texture.hpp
						
						tt05_textured_cube/TransformVertexShader.vertexshader
						tt05_textured_cube/TextureFragmentShader.fragmentshader
)
target_link_libraries(exett05 ${ALL_LIBS})

# Xcode and Visual working directories
set_target_properties(exett05 PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/tt05_textured_cube/")
create_target_launcher(exett05 WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/tt05_textured_cube/")


# Tutorial 6
add_executable(exett06 tt06_keyboard_and_mouse/main.cpp
						common/shader.cpp
						common/shader.hpp
						common/controls.cpp
						common/controls.hpp
						common/texture.cpp
						common/texture.hpp
	
						tt06_keyboard_and_mouse/TransformVertexShader.vertexshader
						tt06_keyboard_and_mouse/TextureFragmentShader.fragmentshader
)
target_link_libraries(exett06 ${ALL_LIBS})

# Xcode and Visual working directories
set_target_properties(exett06 PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/tt06_keyboard_and_mouse/")
create_target_launcher(exett06 WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/tt06_keyboard_and_mouse/")








SOURCE_GROUP(common REGULAR_EXPRESSION ".*/common/.*" )
SOURCE_GROUP(shaders REGULAR_EXPRESSION ".*/.*shader$" )

if (NOT ${CMAKE_GENERATOR} MATCHES "Xcode" )
add_custom_command(
   TARGET exett01 POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/exett01${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/tt01_first_window/"
)

add_custom_command(
   TARGET exett02 POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/exett02${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/tt02_red_triangle/"
)

add_custom_command(
   TARGET exett03 POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/exett03${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/tt03_matrices/"
)

add_custom_command(
   TARGET exett04 POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/exett04${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/tt04_colored_cube/"
)

add_custom_command(
   TARGET exett05 POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/exett05${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/tt05_textured_cube/"
)

add_custom_command(
   TARGET exett06 POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/exett06${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/tt06_keyboard_and_mouse/"
)


elseif (${CMAKE_GENERATOR} MATCHES "Xcode" )

endif (NOT ${CMAKE_GENERATOR} MATCHES "Xcode" )

