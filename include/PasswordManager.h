#pragma once
#include <string>
#include <unordered_map>

class PasswordManager {
public:
    PasswordManager();
    ~PasswordManager();
    bool authenticate(const std::string& username, const std::string& password);
    void savePassword(const std::string& username, const std::string& password);
private:
    std::unordered_map<std::string, std::string> passwordDatabase;
};
