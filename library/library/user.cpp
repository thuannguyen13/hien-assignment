#include "user.h"
#include <iostream>

User::User(const std::string &username, const std::string &password, const std::string &name,
           const std::string &address, const std::string &phone, const std::string &userID)
    : username(username), password(password), name(name), address(address), phone(phone), userID(userID) {}

void User::view() const
{
    std::cout << "UserID: " << userID << std::endl;
    std::cout << "Username: " << username << std::endl;
    std::cout << "Password: " << password << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "Phone: " << phone << std::endl;
}

bool User::searchByName(const std::string &searchName) const
{
    return name == searchName;
}

void User::listUsers(const std::vector<User> &users)
{
    std::cout << "List of Users:" << std::endl;
    for (const auto &user : users)
    {
        user.view();
    }
}

void User::searchUser(const std::vector<User> &users)
{
    std::string searchName;
    std::cout << "Enter the name to search: ";
    std::cin >> searchName;

    bool found = false;
    std::cout << "Search results:" << std::endl;
    for (const auto &user : users)
    {
        if (user.searchByName(searchName))
        {
            user.view();
            found = true;
            break;
        }
    }

    if (!found)
    {
        std::cout << "No user found with the provided name." << std::endl;
    }
}

void User::viewUser(const std::vector<User> &users)
{
    int index;
    std::cout << "Enter the index of the user to view: ";
    std::cin >> index;

    if (index >= 0 && index < users.size())
    {
        users[index].view();
    }
    else
    {
        std::cout << "Invalid index." << std::endl;
    }
}

void User::addUser(std::vector<User> &users)
{
    std::string username, password, name, address, phone, userID;

    std::cout << "Enter username: ";
    std::cin >> username;
    // Input for other user details

    users.push_back(User(username, password, name, address, phone, userID));
    std::cout << "User added successfully." << std::endl;
}

void User::deleteUser(std::vector<User> &users)
{
    int index;
    std::cout << "Enter the index of the user to delete: ";
    std::cin >> index;

    if (index >= 0 && index < users.size())
    {
        users.erase(users.begin() + index);
        std::cout << "User deleted successfully." << std::endl;
    }
    else
    {
        std::cout << "Invalid index." << std::endl;
    }
}
