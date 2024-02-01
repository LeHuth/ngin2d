#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <glm/glm.hpp>
#include <imgui/imgui.h>
#include <sol/sol.hpp>

int main(int argc, char* argv[]) {
    glm::vec2 velocity(1.0f, 1.0f);

    sol::state lua;
    lua.open_libraries(sol::lib::base, sol::lib::package);

    std::cout << "Hello, World!" << std::endl;
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Quit();
    return 0;
}
