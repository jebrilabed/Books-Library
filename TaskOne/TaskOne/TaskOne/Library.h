#pragma once
#include <list>
#include <string>
#include "Book.h"
#include "User.h"
using namespace std;
class Library {
private:
    list<Book> Books;
    list<User> Users;

public:
    void loadBooks(const string& filename);
    void saveBooks(const string& filename) const;

    void loadUsers(const string& filename);
    void saveUsers(const string& filename) const;

    void addBooks(const Book& book);
    void printBooks();
    User* findUser(int id);
    void addUser(const User& newUser);
    Book* searchBook(const string& searchKey);
    void borrowBook(User& user, const string& isbn);
    void returnBook(User& user, const string& isbn);
    
};

