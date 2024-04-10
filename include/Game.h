#pragma once
#include <SDL.h>

class Game {
public:
    Game();
    ~Game();
    void init();
    void run();
    void clean();
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool isRunning;
};
