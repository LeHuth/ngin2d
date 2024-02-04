//
// Created by leona on 2/1/2024.
//
#include <iostream>
#include "Game.h"
#include <SDL.h>

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

void Game::update(){
}

void Game::render(){
    SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
    SDL_RenderClear(renderer);

    // render stuff
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_Rect rect = { 10, 10, 100, 100 };
    SDL_RenderFillRect(renderer, &rect);

    // swap front and back buffers
    SDL_RenderPresent(renderer);
}

void Game::clean(){
}

bool Game::isRunning() const {
    return running;
}
