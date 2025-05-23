#pragma once
#include <string>
#include <iostream>
#include "json.hpp"
using namespace std;
class Book {
private:
    string Title, Author, Isbn;
    bool isAvailable;

public:
    Book();
    Book(string title, string author, string isbn);

    bool operator==(const Book& other) const;

    void setTitle(const string& title);
    string getTitle() const;
    void setAuthor(const string& author);
    string getAuthor() const;
    void setIsbn(const string& isbn);
    string getIsbn() const;
    void setIsAvailable(bool available);
    bool getIsAvailable() const;
    void printBookInf();

    nlohmann::json toJson() const;
    static Book fromJson(const nlohmann::json& j);
};


