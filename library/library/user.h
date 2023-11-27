#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <vector>

class User {
public:
    User(const std::string& username, const std::string& password, const std::string& name,
        const std::string& address, const std::string& phone, const std::string& userID);

    void view() const;
    bool searchByName(const std::string& searchName) const;

    static void listUsers(const std::vector<User>& users);
    static void searchUser(const std::vector<User>& users);
    static void viewUser(const std::vector<User>& users);
    static void addUser(std::vector<User>& users);
    static void deleteUser(std::vector<User>& users);

private:
    std::string username;
    std::string password;
    std::string name;
    std::string address;
    std::string phone;
    std::string userID;
};

#endif // USER_H
