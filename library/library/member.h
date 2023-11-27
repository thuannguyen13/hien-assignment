#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>

class Member {
public:
    Member(){}
    Member(const std::string& name, int ID, const std::string& contactInfo);

    // Getters
    std::string getName() const;
    int getID() const;
    int getMemberID() const;
    std::string getContactInfo() const;

    void view() const;

    static void listMembers(const std::vector<Member>& members);
    static void searchMember(const std::vector<Member>& members, const std::string& searchCriteria);
    static void addNewMember(std::vector<Member>& members);
    static void deleteMember(std::vector<Member>& members, int memberID);

private:
    std::string name;
    int ID;
    int memberID;
    std::string contactInfo;
};

#endif // MEMBER_H
