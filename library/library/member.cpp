#include "member.h"
#include <iostream>

Member::Member(const std::string& name, int ID, const std::string& contactInfo)
    : name(name), ID(ID), contactInfo(contactInfo) {}

std::string Member::getName() const {
    return name;
}

int Member::getID() const {
    return ID;
}
int Member::getMemberID() const {
    return memberID;
}
std::string Member::getContactInfo() const {
    return contactInfo;
}

void Member::view() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "ID: " << ID << std::endl;
    std::cout << "Contact Info: " << contactInfo << std::endl;
}

void Member::listMembers(const std::vector<Member>& members) {
    for (const auto& member : members) {
        member.view();
        std::cout << "=============================" << std::endl;
    }
}

void Member::searchMember(const std::vector<Member>& members, const std::string& searchCriteria) {
    for (const auto& member : members) {
        if (member.getName() == searchCriteria || std::to_string(member.getID()) == searchCriteria) {
            member.view();
            std::cout << "=============================" << std::endl;
            return;
        }
    }
    std::cout << "Member not found." << std::endl;
}

void Member::addNewMember(std::vector<Member>& members) {
    std::string name, contactInfo;
    int ID;

    std::cout << "Enter member name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Enter member ID: ";
    std::cin >> ID;

    std::cin.ignore();
    std::cout << "Enter contact info: ";
    std::getline(std::cin, contactInfo);

    members.emplace_back(name, ID, contactInfo);
    std::cout << "Member added successfully!" << std::endl;
}

void Member::deleteMember(std::vector<Member>& members, int memberID) {
    auto it = std::find_if(members.begin(), members.end(), [memberID](const Member& member) {
        return member.getID() == memberID;
        });

    if (it != members.end()) {
        members.erase(it);
        std::cout << "Member deleted successfully!" << std::endl;
    }
    else {
        std::cout << "Member not found." << std::endl;
    }
}
