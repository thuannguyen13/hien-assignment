#include <iostream>
#include <algorithm>
#include <vector>

#include "book.h"
#include "member.h"
#include "user.h"
#include "library.h"
#include "transaction.h"
#include "catalog.h"

using namespace std;

// Menu cho lớp Book
void bookMenu(vector<Book> &books, const std::string &searchCriteria)
{
    int choice;
    do
    {
        cout << "===== BOOK MENU =====" << endl;
        cout << "1. View Books" << endl;
        cout << "2. List Book" << endl;
        cout << "3. Search Book" << endl;
        cout << "4. Add New Book" << endl;
        cout << "5. Delete Book" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Book::listBooks(books);
            break;
        case 2:
        {
            string searchCriteria;
            cout << "Enter search criteria (title, author, or ID): ";
            cin >> searchCriteria;
            Book::searchBook(books, searchCriteria);
            break;
        }
        case 3:
        {
            int viewID;
            cout << "Enter book ID to view: ";
            cin >> viewID;
            // Search for the book by ID and view its details
            Book::searchBook(books, to_string(viewID));
            break;
        }
        case 4:
            Book::addNewBook(books);
            break;
        case 5:
        {
            int deleteID;
            cout << "Enter book ID to delete: ";
            cin >> deleteID;
            Book::deleteBook(books, deleteID);
            break;
        }
        case 0:
            cout << "Returning to Main Menu." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (choice != 0);
}
void memberMenu(vector<Member> &members, const string &searchCriteria)
{
    int choice;
    do
    {
        cout << "===== MEMBER MENU =====" << endl;
        cout << "1. View Members" << endl;
        cout << "2. List Member" << endl;
        cout << "3. Search Member" << endl;
        cout << "4. Add New Member" << endl;
        cout << "5. Delete Member" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Member::listMembers(members);
            break;
        case 2:
        {
            string searchCriteria;
            cout << "Enter search criteria (name or ID): ";
            cin >> searchCriteria;
            Member::searchMember(members, searchCriteria);
            break;
        }
        case 3:
        {
            int viewID;
            cout << "Enter member ID to view: ";
            cin >> viewID;
            Member::searchMember(members, to_string(viewID));
            break;
        }
        case 4:
            Member::addNewMember(members);
            break;
        case 5:
        {
            int deleteID;
            cout << "Enter member ID to delete: ";
            cin >> deleteID;
            Member::deleteMember(members, deleteID);
            break;
        }
        case 0:
            cout << "Returning to Main Menu." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (choice != 0);
}
void userSubMenu(std::vector<User> &users)
{
    int choice;
    do
    {
        std::cout << "===== USER SUBMENU =====" << std::endl;
        std::cout << "1. View All Users" << std::endl;
        std::cout << "2. Search User" << std::endl;
        std::cout << "3. View User Details" << std::endl;
        std::cout << "4. Add New User" << std::endl;
        std::cout << "5. Delete User" << std::endl;
        std::cout << "0. Back to Main Menu" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            User::listUsers(users);
            break;
        case 2:
            User::searchUser(users);
            break;
        case 3:
            User::viewUser(users);
            break;
        case 4:
            User::addUser(users);
            break;
        case 5:
            User::deleteUser(users);
            break;
        case 0:
            std::cout << "Returning to Main Menu." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    } while (choice != 0);
}

void libraryMenu(Library &library)
{
    int choice;
    do
    {
        cout << "===== LIBRARY MANAGEMENT =====" << endl;
        cout << "1. View All Books" << endl;
        cout << "2. View All Members" << endl;
        cout << "3. View All Transactions" << endl;
        cout << "4. Add New Book" << endl;
        cout << "5. Add New Member" << endl;
        cout << "6. Add New Transaction" << endl;
        cout << "7. Delete Book" << endl;
        cout << "8. Delete Member" << endl;
        cout << "9. Delete Transaction" << endl;
        cout << "0. Back to Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            library.viewAllBooks();
            break;
        case 2:
            library.viewAllMembers();
            break;
        case 3:
            library.viewAllTransactions();
            break;
        case 4:
        {
            Book newBook;
            // Nhập thông tin cho newBook
            library.addBook(newBook);
            break;
        }
        case 5:
        {
            Member newMember;
            // Nhập thông tin cho newMember
            library.addMember(newMember);
            break;
        }
        case 6:
        {
            Transaction newTransaction;
            // Nhập thông tin cho newTransaction
            library.addTransaction(newTransaction);
            break;
        }
        case 7:
        {
            int bookID;
            cout << "Enter book ID to delete: ";
            cin >> bookID;
            library.deleteBook(bookID);
            break;
        }
        case 8:
        {
            int memberID;
            cout << "Enter member ID to delete: ";
            cin >> memberID;
            library.deleteMember(memberID);
            break;
        }
        case 9:
        {
            int transactionID;
            cout << "Enter transaction ID to delete: ";
            cin >> transactionID;
            library.deleteTransaction(transactionID);
            break;
        }
        case 0:
            cout << "Returning to Main Menu." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    } while (choice != 0);
}
void catalogSubMenu(const Catalog &catalog)
{
    int choice;
    do
    {
        std::cout << "===== CATALOG SUBMENU =====" << std::endl;
        std::cout << "1. View Books by Author" << std::endl;
        std::cout << "2. View Books by Title" << std::endl;
        std::cout << "3. View Books by Year" << std::endl;
        std::cout << "4. View Books by Category" << std::endl;
        std::cout << "0. Back to Main Menu" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            std::string author;
            std::cout << "Enter author's name: ";
            std::cin.ignore();
            std::getline(std::cin, author);
            catalog.viewBooksByAuthor(author);
            break;
        }
        case 2:
        {
            std::string title;
            std::cout << "Enter book title: ";
            std::cin.ignore();
            std::getline(std::cin, title);
            catalog.viewBooksByTitle(title);
            break;
        }
        case 3:
        {
            int year;
            std::cout << "Enter publication year: ";
            std::cin >> year;
            catalog.viewBooksByYear(year);
            break;
        }
        case 4:
        {
            std::string category;
            std::cout << "Enter category: ";
            std::cin.ignore();
            std::getline(std::cin, category);
            catalog.viewBooksByCategory(category);
            break;
        }
        case 0:
            std::cout << "Returning to Main Menu." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    } while (choice != 0);
}
void transactionSubMenu(std::vector<Transaction> &transactions)
{
    int choice;
    do
    {
        std::cout << "===== TRANSACTION SUBMENU =====" << std::endl;
        std::cout << "1. View All Transactions" << std::endl;
        std::cout << "2. Search Transaction" << std::endl;
        std::cout << "3. Add New Transaction" << std::endl;
        std::cout << "4. Delete Transaction" << std::endl;
        std::cout << "0. Back to Main Menu" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {

        case 1:
        {
            Transaction::listTransactions(transactions);
            break;
        }

        case 2:
        {
            int searchTransactionID;
            std::cout << "Enter transaction ID to search: ";
            std::cin >> searchTransactionID;
            Transaction::searchTransaction(transactions, searchTransactionID);
            break;
        }
        case 3:
        {
            int memberID, bookID;
            std::string borrowDate, returnDate;
            std::cout << "Enter Member ID: ";
            std::cin >> memberID;
            std::cout << "Enter Book ID: ";
            std::cin >> bookID;
            std::cout << "Enter Borrow Date (YYYY-MM-DD): ";
            std::cin >> borrowDate;
            std::cout << "Enter Return Date (YYYY-MM-DD): ";
            std::cin >> returnDate;
            Transaction::addNewTransaction(transactions, memberID, bookID, borrowDate, returnDate);
            break;
        }
        case 4:
        {
            int deleteTransactionID;
            std::cout << "Enter transaction ID to delete: ";
            std::cin >> deleteTransactionID;
            Transaction::deleteTransaction(transactions, deleteTransactionID);
            break;
        }
        case 0:
            std::cout << "Returning to Main Menu." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    } while (choice != 0);
}

int main()
{
    vector<Book> books;
    vector<Member> members;
    vector<User> users;
    Library library;                  // Khởi tạo đối tượng thư viện
    vector<Transaction> transactions; // Khởi tạo danh sách giao dịch
    Catalog catalog(books);           // Sử dụng tên khác để tránh xung đột

    int mainChoice;
    do
    {
        cout << "===== MAIN MENU =====" << endl;
        cout << "1. Book Management" << endl;
        cout << "2. Member Management" << endl;
        cout << "3. User Management" << endl;
        cout << "4. Library Management" << endl;
        cout << "5. Transaction Management" << endl;
        cout << "6. Catalog Management" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> mainChoice;

        switch (mainChoice)
        {
        case 1:
            bookMenu(books, ""); // Truyền tham số trống vào searchCriteria
            break;
        case 2:
            memberMenu(members, ""); // Truyền tham số trống vào searchCriteria
            break;
        case 3:
            userSubMenu(users); // Sử dụng submenu của người dùng
            break;
        case 4:
            libraryMenu(library); // Sử dụng submenu của thư viện
            break;
        case 5:
            transactionSubMenu(transactions); // Sử dụng submenu của giao dịch
            break;
        case 6:
            catalogSubMenu(catalog); // Sử dụng submenu của danh mục
            break;
        case 0:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (mainChoice != 0);

    return 0;
}
