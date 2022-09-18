# CMakeList.txt : CMake project for CHPT1, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

find_package(glew REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)


add_executable (CHPT1 "CHPT1.cpp" "CHPT1.h" "LoadShaders.h" "LoadShaders.cpp" "vgl.h")

#if (CMAKE_VERSION VERSION_GREATER 3.12)
#set_property(TARGET CHPT1 PROPERTY CXX_STANDARD 20)
#endif()

find_path(TINYGLTF_INCLUDE_DIRS "tiny_gltf.h")
target_include_directories(CHPT1 PRIVATE ${TINYGLTF_INCLUDE_DIRS})


target_link_libraries(CHPT1 GLEW::GLEW glfw glad::glad glm::glm imgui::imgui)

file(GLOB MODELS
  "assets/models/*.glb"
)


file(GLOB SHADERS
  "assets/shaders/*.*"
)



function (CopyFile ORIGINAL_TARGET FILE_PATH COPY_OUTPUT_DIRECTORY)
    # Copy to the disk at build time so that when the header file changes, it is detected by the build system.
    set(input ${FILE_PATH})
    get_filename_component(file_name ${FILE_PATH} NAME)
    set(output ${COPY_OUTPUT_DIRECTORY}/${file_name})
    set(copyTarget ${ORIGINAL_TARGET}-${file_name})

    add_custom_target(${copyTarget} DEPENDS ${output})
    add_dependencies(${ORIGINAL_TARGET} ${copyTarget})
    add_custom_command(
            DEPENDS ${input}
            OUTPUT ${output}
            COMMAND ${CMAKE_COMMAND} -E copy_if_different ${input} ${output}
            COMMENT "Copying file to ${output}."
    )
endfunction ()

foreach(SHADER IN LISTS SHADERS)
    CopyFile(CHPT1 ${SHADER} shaders)
endforeach()

foreach(MODEL IN LISTS MODELS)
    CopyFile(CHPT1 ${MODEL} models)
endforeach()