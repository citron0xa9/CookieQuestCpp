set(target CookieQuestCpp)

find_package(GLFW REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLM REQUIRED)
find_package(Threads REQUIRED)
find_package(OpenGL REQUIRED)

file(GLOB sources "*.cpp" "*.h" "graphics-core/*.cpp" "graphic-core/*.h" "objects/*.cpp" "objects/*.h" "utils/*.cpp" "utils/*.h")

add_executable(${target} ${sources})

target_link_libraries(${target} ${OPENGL_LIBRARIES} ${GLFW_LIBRARIES} ${GLEW_LIBRARY} ${CMAKE_THREAD_LIBS_INIT})
target_include_directories(${target} PUBLIC "graphics-core" "objects" "utils" ${GLM_INCLUDE_DIRS} ${GLFW_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})
