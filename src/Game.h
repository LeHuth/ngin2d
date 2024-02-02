//
// Created by leona on 2/1/2024.
//

#ifndef INC_2DGAMEENGINE_GAME_H
#define INC_2DGAMEENGINE_GAME_H


#include <SDL.h>

/**
 * Game class using the RAII pattern
 */
class Game {
public:
    Game();
    ~Game();
    void init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();
    void run();
    bool isRunning() const;
private:
    bool running;

    SDL_Window *window;
    SDL_Renderer *renderer;
};


#endif //INC_2DGAMEENGINE_GAME_H
