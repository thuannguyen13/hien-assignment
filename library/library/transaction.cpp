#include "transaction.h"
#include <iostream>

Transaction::Transaction(int transactionID, int memberID, int bookID, const std::string &borrowDate, const std::string &returnDate)
    : transactionID(transactionID), memberID(memberID), bookID(bookID), borrowDate(borrowDate), returnDate(returnDate) {}

int Transaction::getTransactionID() const
{
    return transactionID;
}

int Transaction::getMemberID() const
{
    return memberID;
}

int Transaction::getBookID() const
{
    return bookID;
}

std::string Transaction::getBorrowDate() const
{
    return borrowDate;
}

std::string Transaction::getReturnDate() const
{
    return returnDate;
}

void Transaction::view() const
{
    std::cout << "Transaction ID: " << transactionID << std::endl;
    std::cout << "Member ID: " << memberID << std::endl;
    std::cout << "Book ID: " << bookID << std::endl;
    std::cout << "Borrow Date: " << borrowDate << std::endl;
    std::cout << "Return Date: " << returnDate << std::endl;
}

void Transaction::listTransactions(const std::vector<Transaction> &transactions)
{
    for (const auto &transaction : transactions)
    {
        transaction.view();
        std::cout << "=============================" << std::endl;
    }
}

void Transaction::searchTransaction(const std::vector<Transaction> &transactions, int transactionID)
{
    for (const auto &transaction : transactions)
    {
        if (transaction.getTransactionID() == transactionID)
        {
            transaction.view();
            std::cout << "=============================" << std::endl;
            return;
        }
    }
    std::cout << "Transaction not found." << std::endl;
}

void Transaction::addNewTransaction(std::vector<Transaction> &transactions, int memberID, int bookID, const std::string &borrowDate, const std::string &returnDate)
{
    int newTransactionID = transactions.empty() ? 1 : transactions.back().getTransactionID() + 1;
    transactions.emplace_back(newTransactionID, memberID, bookID, borrowDate, returnDate);
    std::cout << "Transaction added successfully!" << std::endl;
}

void Transaction::deleteTransaction(std::vector<Transaction> &transactions, int transactionID)
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
