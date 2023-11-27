#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "book.h"
#include "member.h"
#include "transaction.h"

class Library
{
public:
    Library();

    void viewAllBooks() const;
    void viewAllMembers() const;
    void viewAllTransactions() const;

    void addBook(const Book &book);
    void addMember(const Member &member);
    void addTransaction(const Transaction &transaction);

    void deleteBook(int bookID);
    void deleteMember(int memberID);
    void deleteTransaction(int transactionID);

private:
    std::vector<Book> books;
    std::vector<Member> members;
    std::vector<Transaction> transactions;

    int generateBookID() const;
    int generateMemberID() const;
    int generateTransactionID() const;
};

#endif // LIBRARY_H
