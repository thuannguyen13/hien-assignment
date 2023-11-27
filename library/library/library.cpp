#include <iostream>
#include <algorithm>
#include "library.h"
#include "transaction.h"
#include "book.h"

Library::Library() {}

void Library::viewAllBooks() const
{
    for (const auto &book : books)
    {
        book.view();
        std::cout << "=============================" << std::endl;
    }
}

void Library::viewAllMembers() const
{
    for (const auto &member : members)
    {
        member.view();
        std::cout << "=============================" << std::endl;
    }
}

void Library::viewAllTransactions() const
{
    for (const auto &transaction : transactions)
    {
        transaction.view();
        std::cout << "=============================" << std::endl;
    }
}

void Library::addBook(const Book &book)
{
    books.push_back(book);
    std::cout << "Book added successfully!" << std::endl;
}

void Library::addMember(const Member &member)
{
    members.push_back(member);
    std::cout << "Member added successfully!" << std::endl;
}

void Library::addTransaction(const Transaction &transaction)
{
    transactions.push_back(transaction);
    std::cout << "Transaction added successfully!" << std::endl;
}

void Library::deleteBook(int bookID)
{
    auto it = std::find_if(books.begin(), books.end(), [bookID](const Book &book)
                           { return book.getBookID() == bookID; });

    if (it != books.end())
    {
        books.erase(it);
        std::cout << "Book deleted successfully!" << std::endl;
    }
    else
    {
        std::cout << "Book not found." << std::endl;
    }
}

void Library::deleteMember(int memberID)
{
    auto it = std::find_if(members.begin(), members.end(), [memberID](const Member &member)
                           { return member.getMemberID() == memberID; });

    if (it != members.end())
    {
        members.erase(it);
        std::cout << "Member deleted successfully!" << std::endl;
    }
    else
    {
        std::cout << "Member not found." << std::endl;
    }
}

void Library::deleteTransaction(int transactionID)
{
    auto it = std::find_if(transactions.begin(), transactions.end(), [transactionID](const Transaction &transaction)
                           { return transaction.getTransactionID() == transactionID; });

    if (it != transactions.end())
    {
        transactions.erase(it);
        std::cout << "Transaction deleted successfully!" << std::endl;
    }
    else
    {
        std::cout << "Transaction not found." << std::endl;
    }
}

// Phương thức sinh ID
int Library::generateBookID() const
{
    return books.empty() ? 1 : books.back().getBookID() + 1;
}

int Library::generateMemberID() const
{
    return members.empty() ? 1 : members.back().getMemberID() + 1;
}

int Library::generateTransactionID() const
{
    return transactions.empty() ? 1 : transactions.back().getTransactionID() + 1;
}
