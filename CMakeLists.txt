cmake_minimum_required(VERSION 3.26)
project(2dgameengine)

set(CMAKE_CXX_STANDARD 17)
include_directories(C:/SDL2/include)
include_directories(C:/Users/leona/CLionProjects/2dgameengine/libs)
link_directories(C:/SDL2/lib/x64) # Use lib/x86 if you're on a 32-bit system
link_directories(C:/Users/leona/CLionProjects/2dgameengine/libs/lua)
add_executable(2dgameengine main.cpp
        src/Game.cpp
        src/Game.h
        src/Game.h)
target_link_libraries(${PROJECT_NAME} SDL2main SDL2_image SDL2 lua)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "C:/SDL2/lib/x64/SDL2_image.dll"
        "C:/SDL2/lib/x64/SDL2.dll"
        "C:/Users/leona/CLionProjects/2dgameengine/libs/lua/lua54.dll"
        $<TARGET_FILE_DIR:${PROJECT_NAME}>)
