#include "Login.h"

Login::Login(SDL_Renderer* renderer) : renderer(renderer), loggedIn(false), typingUsername(true), typingPassword(false) {}

Login::~Login() {}

bool Login::handleEvents(SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
            case SDLK_TAB:
                if (typingUsername) {
                    typingUsername = false;
                    typingPassword = true;
                } else {
                    typingUsername = true;
                    typingPassword = false;
                }
                break;
            case SDLK_RETURN:
                if (loggedIn) {
                    return true; 
                }
                break;
            default:
                handleTextInput(event);
                break;
        }
    }
    return false;
}

void Login::handleTextInput(SDL_Event& event) {
    if (typingUsername) {
        if (event.text.text[0] == '\b' && username.length() > 0) {
            username.pop_back();
        } else if (event.text.text[0] != '\b') {
            username += event.text.text;
        }
    } else if (typingPassword) {
        if (event.text.text[0] == '\b' && password.length() > 0) {
            password.pop_back();
        } else if (event.text.text[0] != '\b') {
            password += event.text.text;
        }
    }
}

void Login::handleBackspace() {
    if (typingUsername && username.length() > 0) {
        username.pop_back();
    } else if (typingPassword && password.length() > 0) {
        password.pop_back();
    }
}

void Login::render() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

bool Login::isLoggedIn() const {
    return loggedIn;
}
