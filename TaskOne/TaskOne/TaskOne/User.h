#pragma once
#include <string>
#include <list>
#include "Book.h"
#include "json.hpp"
using namespace std;
class User {
private:
    int userId;
    string Name;
    list<Book> BorrowedBooks;

public:
    User();
    User(string name, int id);

    void setUserId(int id);
    int getUserId() const;
    void setName(const std::string& name);
    string getName() const;
    list<Book> getBorrowedBooks() const;
    void borrowBook(Book& book);
    void returnBook(Book& book);
    void printBorrowedBooks() const;

    nlohmann::json toJson() const;
    static User fromJson(const nlohmann::json& j);
};



