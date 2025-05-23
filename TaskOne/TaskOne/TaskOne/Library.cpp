#include "Library.h"
#include <fstream>
#include <iostream>
#include "json.hpp"
#include "Book.h"
using namespace std;
using json = nlohmann::json;

void Library::loadBooks(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) return;

    json j;
    file >> j;
    for (const json& item : j) {
        Books.push_back(Book::fromJson(item));
    }
}

void Library::saveBooks(const string& filename) const {
    ofstream file(filename);
    json j = json::array();
    for (const Book& book : Books) {
        j.push_back(book.toJson());
    }
    file << j.dump(4);
}

void Library::loadUsers(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) return;

    json j;
    file >> j;
    for (const json& item : j) {
        Users.push_back(User::fromJson(item));
    }
}

void Library::saveUsers(const string& filename) const {
    ofstream file(filename);
    json j = json::array();
    for (const User& user : Users) {
        j.push_back(user.toJson());
    }
    file << j.dump(4);
}

void Library::addBooks(const Book& book) {
    Books.push_back(book);
}

void Library::printBooks(){
    for ( Book& book : Books) {
        book.printBookInf();
    }
}

User* Library::findUser(int id) {
    for (User& u : Users)
        if (u.getUserId() == id)
            return &u;
    return nullptr;
}

void Library::addUser(const User& newUser) {
    Users.push_back(newUser);
}

Book* Library::searchBook(const string& searchKey)
{
    for (Book& b : Books)
        if (b.getIsbn() == searchKey || b.getTitle() == searchKey) {
            return &b;
        }
    return nullptr;
}

void Library::borrowBook(User& user, const string& isbn) {
    Book* book = searchBook(isbn);
    if (book && book->getIsAvailable()) {
        user.borrowBook(*book);
        book->setIsAvailable(false);
        cout << "Book borrowed successfully." << endl;
    }
    else {
        cout << "Book not available." << endl;
    }
}

void Library::returnBook(User& user, const string& isbn) {
    Book* book = searchBook(isbn);
    if (book) {
        for (Book& b : user.getBorrowedBooks()) {
            if (b == *book) {
                user.returnBook(*book);
                book->setIsAvailable(true);
                cout << "Book returned successfully." << endl;
                return;
            }
        }
    }
    else {
        cout << "The Book Is Not Found" << endl;
    }
    cout << "The Book Is Not In Your Borrowed Books List" << endl;

}




