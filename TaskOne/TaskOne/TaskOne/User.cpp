#include "User.h"
#include <iostream>
using namespace std;
User::User() = default;

User::User(string name, int id) : Name(name), userId(id) {}

void User::setUserId(int id) { userId = id; }

int User::getUserId() const { return userId; }

void User::setName(const string& name) { Name = name; }

string User::getName() const { return Name; }

list<Book> User::getBorrowedBooks() const
{
    return BorrowedBooks;
}

void User::borrowBook(Book& book) {
    book.setIsAvailable(false);
    BorrowedBooks.push_back(book);
}

void User::returnBook(Book& book) {
    book.setIsAvailable(true);
    BorrowedBooks.remove(book);
}

void User::printBorrowedBooks() const {
    for (const Book& b : BorrowedBooks) {
        cout << b.getTitle() << " by " << b.getAuthor()
            << " [" << b.getIsbn() << "]" << endl;
    }
}

nlohmann::json User::toJson() const {
    nlohmann::json borrowed = nlohmann::json::array();
    for (const auto& b : BorrowedBooks)
        borrowed.push_back(b.toJson());

    return {
        {"userId", userId},
        {"Name", Name},
        {"BorrowedBooks", borrowed}
    };
}

User User::fromJson(const nlohmann::json& j) {
    User u;
    u.setUserId(j.at("userId").get<int>());
    u.setName(j.at("Name").get<string>());

    for (const auto& item : j.at("BorrowedBooks")) {
        u.BorrowedBooks.push_back(Book::fromJson(item));
    }

    return u;
}



