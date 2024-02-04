//
// Created by leona on 2/1/2024.
//

#ifndef INC_2DGAMEENGINE_GAME_H
#define INC_2DGAMEENGINE_GAME_H

#include <glm/glm.hpp>
#include <SDL.h>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const Uint32 FPS = 60;
const Uint32 FRAME_DELAY = 1000 / FPS;

/**
 * Game class using the RAII pattern
 */
class Game {
public:
    Game();
    ~Game();
    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void setup();
    void update();
    void render();
    void clean();
    void run();
    bool isRunning() const;
private:
    bool running;

    SDL_Window *window;
    SDL_Renderer *renderer;
    glm::vec2 position;
    glm::vec2 velocity;
    uint32_t ticksLastFrame = 0;
};


#endif //INC_2DGAMEENGINE_GAME_H
