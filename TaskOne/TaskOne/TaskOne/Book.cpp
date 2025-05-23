#include "Book.h"
using namespace std;
Book::Book() : isAvailable(true) {}

Book::Book(string title, string author, string isbn)
    : Title(title), Author(author), Isbn(isbn), isAvailable(true) {
}

bool Book::operator==(const Book& other) const {
    return Title == other.Title && Author == other.Author;
}

void Book::setTitle(const string& title) {Title = title; }

string Book::getTitle() const { return Title; }

void Book::setAuthor(const string& author) { Author = author; }

string Book::getAuthor() const { return Author; }

void Book::setIsbn(const string& isbn) { Isbn = isbn; }

string Book::getIsbn() const { return Isbn; }

void Book::setIsAvailable(bool available) { isAvailable = available; }

bool Book::getIsAvailable() const { return isAvailable; }

void Book::printBookInf()
{
    cout << Title << " by " << Author << " [" << Isbn << "] " << (isAvailable?"(Available)":"(Not Avilable)") << endl;
}

nlohmann::json Book::toJson() const {
    return {
        {"Title", Title},
        {"Author", Author},
        {"Isbn", Isbn},
        {"isAvailable", isAvailable}
    };
}

Book Book::fromJson(const nlohmann::json& j) {
    Book b;
    b.setTitle(j.at("Title").get<std::string>());
    b.setAuthor(j.at("Author").get<std::string>());
    b.setIsbn(j.at("Isbn").get<std::string>());
    b.setIsAvailable(j.at("isAvailable").get<bool>());
    return b;
}

