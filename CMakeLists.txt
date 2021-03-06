
cmake_minimum_required(VERSION 2.8)
project(MusicGame)

# Add deps subdirectory
add_subdirectory(dependencies)

# Get all source files from src
aux_source_directory(src SRC_LIST)
aux_source_directory(src/entities SRC_LIST2)

# Get Include Directories
set (INCLUDE_DIRS include
	dependencies/glfw/include/GLFW
	dependencies/glew/include/GL
	dependencies/glm/glm
	dependencies/glm/gtc
	dependencies/glm/gtx
)

include_directories(${INCLUDE_DIRS})

# Add executable to project
add_executable(${PROJECT_NAME} ${SRC_LIST} ${SRC_LIST2})

# Link GLFW and GLEW to main executable
target_link_libraries(${PROJECT_NAME} libglew_static glfw ${GLFW_LIBRARIES} )

# Define GLEW_STATIC for Windows
#if(MSVC)
#	add_definitions(-DGLEW_STATIC)
#endif()

# C++ Standard
add_definitions( -std=c++0x )

