#include "PasswordManager.h"

PasswordManager::PasswordManager() {}

PasswordManager::~PasswordManager() {}

bool PasswordManager::authenticate(const std::string& username, const std::string& password) {
    auto it = passwordDatabase.find(username);
    if (it != passwordDatabase.end() && it->second == password) {
        return true;
    }
    return false;
}

void PasswordManager::savePassword(const std::string& username, const std::string& password) {
    passwordDatabase[username] = password;
}
