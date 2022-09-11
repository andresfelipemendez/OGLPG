# CMakeList.txt : CMake project for CHPT1, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

find_package(GLEW REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)


add_executable (CHPT1 "CHPT1.cpp" "CHPT1.h")

#if (CMAKE_VERSION VERSION_GREATER 3.12)
#set_property(TARGET CHPT1 PROPERTY CXX_STANDARD 20)
#endif()

find_path(TINYGLTF_INCLUDE_DIRS "tiny_gltf.h")
target_include_directories(CHPT1 PRIVATE ${TINYGLTF_INCLUDE_DIRS})


target_link_libraries(CHPT1 GLEW::GLEW glfw glad::glad glm::glm imgui::imgui)

