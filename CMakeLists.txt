cmake_minimum_required(VERSION 3.29)
project(2dAnimation)

set(CMAKE_CXX_STANDARD 20)

# SFML stuff
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

add_executable(2dAnimation main.cpp
        src/Display.cpp
        include/Display.h
        include/AnimatedEntity.h
        src/AnimatedEntity.cpp
        src/Snake.cpp
        include/Snake.h
        include/MoveUtilities.h
        include/DrawUtilities.h
)

find_package(SFML COMPONENTS system window graphics audio CONFIG REQUIRED)
find_package(ImGui-SFML CONFIG REQUIRED)
find_package(Eigen3 CONFIG REQUIRED)

target_link_libraries(2dAnimation PRIVATE sfml-system sfml-network sfml-graphics sfml-window sfml-audio)
target_link_libraries(2dAnimation PRIVATE ImGui-SFML::ImGui-SFML)
target_link_libraries(2dAnimation PRIVATE Eigen3::Eigen)


#find_package(imgui CONFIG REQUIRED)
#target_link_libraries(main PRIVATE imgui::imgui)

if(WIN32)
    add_custom_command(
            TARGET 2dAnimation
            COMMENT "Copy OpenAL DLL"
            PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:2dAnimation>
            VERBATIM)
endif()