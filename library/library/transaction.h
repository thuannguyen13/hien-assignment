#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <vector>

class Transaction {
public:
    Transaction(){}
    Transaction(int transactionID, int memberID, int bookID, const std::string& borrowDate, const std::string& returnDate);

    // Getters
    int getTransactionID() const;
    int getMemberID() const;
    int getBookID() const;
    std::string getBorrowDate() const;
    std::string getReturnDate() const;

    void view() const;

    static void listTransactions(const std::vector<Transaction>& transactions);
    static void searchTransaction(const std::vector<Transaction>& transactions, int transactionID);
    static void addNewTransaction(std::vector<Transaction>& transactions, int memberID, int bookID, const std::string& borrowDate, const std::string& returnDate);
    static void deleteTransaction(std::vector<Transaction>& transactions, int transactionID);

private:
    int transactionID;
    int memberID;
    int bookID;
    std::string borrowDate;
    std::string returnDate;
};

#endif // TRANSACTION_H
