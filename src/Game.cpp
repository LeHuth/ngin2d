//
// Created by leona on 2/1/2024.
//
#include <iostream>
#include "Game.h"
#include <SDL.h>
#include <SDL_image.h>

Game::Game() {
    std::cout << "Game constructor called" << std::endl;
    running = false;
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "Failed to initialize SDL" << std::endl;
    }

    window = SDL_CreateWindow("2DGameEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    if(!window) {
        std::cout << "Failed to create window" << std::endl;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    if(!renderer) {
        std::cout << "Failed to create renderer" << std::endl;
        return;
    }
    running = true;
    setup();
}

Game::~Game() {
    std::cout << "Game destructor called" << std::endl;
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void Game::run() {
    while(running) {
        handleEvents();
        update();
        render();
    }
}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen){
}

void Game::handleEvents(){
    SDL_Event event;
    while(SDL_PollEvent(&event)) {
        switch(event.type) {
            case SDL_QUIT:
                running = false;
                break;
            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_ESCAPE) {
                    running = false;
                }
                break;
            default:
                break;
        }
    }
}

void Game::setup(){
    position = glm::vec2(0, 0);
    velocity = glm::vec2(1, 1);
}

void Game::update(){
    Uint32 ticksLastFrame;
    ticksLastFrame = SDL_GetTicks64(); // get timestamp from last frame
    Uint32 timeToWait = FRAME_DELAY - (SDL_GetTicks() - ticksLastFrame); // calculate time to wait
    if(timeToWait <= FRAME_DELAY) {
        SDL_Delay(timeToWait); // delay if frame was too fast
    }
    
    position.x += velocity.x;
    position.y += velocity.y;
    if(position.x > 800 -32 || position.x < 0) {
        velocity.x = -velocity.x;
    }
    if(position.y > 600 -32 || position.y < 0) {
        velocity.y = -velocity.y;
    }
}

void Game::render(){
    SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
    SDL_RenderClear(renderer);

    // render PNG image
    SDL_Surface* pSdlSurface = IMG_Load("../assets/images/cat.png");
    SDL_Texture* pTexture = SDL_CreateTextureFromSurface(renderer, pSdlSurface);
    SDL_FreeSurface(pSdlSurface);

    SDL_Rect dstRect = { static_cast<int>(position.x), static_cast<int>(position.y), 32, 32 };

    SDL_RenderCopy(renderer, pTexture, nullptr, &dstRect);
    SDL_DestroyTexture(pTexture);

    // swap front and back buffers
    SDL_RenderPresent(renderer);
}

void Game::clean(){
}

bool Game::isRunning() const {
    return running;
}
