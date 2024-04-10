#pragma once
#include <SDL.h>
#include <string>

class Login {
public:
    Login(SDL_Renderer* renderer);
    ~Login();
    bool handleEvents(SDL_Event& event);
    void render();
    bool isLoggedIn() const;
private:
    SDL_Renderer* renderer;
    std::string username;
    std::string password;
    bool loggedIn;
    bool typingUsername;
    bool typingPassword;
    void handleTextInput(SDL_Event& event);
    void handleBackspace();
};
