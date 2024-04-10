#include "Game.h"

Game::Game() : window(nullptr), renderer(nullptr), isRunning(false) {}

Game::~Game() {}

void Game::init() {
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("Login System", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    isRunning = true;
}

void Game::run() {
    while (isRunning) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    isRunning = false;
                    break;
            }
        }

        SDL_RenderClear(renderer);
    }
}

void Game::clean() {
    // Clean up SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
