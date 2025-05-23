
#include <iostream>
#include <string>
#include "Library.h"
using namespace std;
enum eChoices
{
    addBook = 1,
    showBooks = 2,
    borrowBook = 3,
    returnBook = 4, 
    showMyBooks = 5,
    searchBook = 6,
    addUser = 7,
    Exit = 0

};

int main() {
    Library lib;
    lib.loadBooks("books.json");
    lib.loadUsers("users.json");

    User user1("Qussay", 100);
    User user2("Anees", 101);
    lib.addUser(user1);
    lib.addUser(user2);
    eChoices eChoice;
    int intChoice;

    do {
        cout << "\n--------Library Menu--------" << endl;
        cout << "1. Add Book\n2. Show Books\n3. Borrow Book\n4. Return Book\n5. Show My Books\n6. Search About Book\n7. Add New User\n0. Exit"<<endl;
        cout << "----------------------------" << endl;
        cout << "Enter Your Choice: ";
        cin >> intChoice;
        cin.ignore();
        cout << "\n";
        eChoice = (eChoices)intChoice;

        switch (eChoice)
        {
        case addBook: {
            string title, author, isbn;
            cout << "Enter Title: ";
            getline(cin, title);
            cout << "Enter Author: ";
            getline(cin, author);
            cout << "Enter ISBN: ";
            getline(cin, isbn);
            if (!lib.searchBook(isbn)) {
                Book b(title, author, isbn);
                lib.addBooks(b);
                lib.saveBooks("books.json");
                cout << "The Book Added Successfully"<<endl;
            }
            else {
                cout << "The User Is Already Added" << endl;
            }
            break;
        }
        case showBooks: {
            lib.printBooks();
            break;
        }
        case returnBook: {
            string isbn;
            int id;
            cout << "Enter Your Id: ";
            cin >> id;
            cin.ignore();
            cout << "Enter ISBN Or Title To Return: ";
            getline(cin, isbn);
            User* u = lib.findUser(id);
            if (u) 
                lib.returnBook(*u, isbn);
            lib.saveBooks("books.json");
            lib.saveUsers("users.json");
            break;
        }
        case borrowBook: {
            string isbn;
            int id;
            cout << "Enter Your Id: ";
            cin >> id;
            cin.ignore();
            cout << "Enter ISBN Or Title To Borrow: ";
            getline(cin, isbn);
            User* u = lib.findUser(id);
            if (u) 
                lib.borrowBook(*u, isbn);
            
            lib.saveBooks("books.json");
            lib.saveUsers("users.json");
            break;
        }
        case showMyBooks: {
            int id;
            cout << "Enter Your Id: ";
            cin >> id;
            cin.ignore();
            User* u = lib.findUser(id);
            if (u) 
                u->printBorrowedBooks();
            break;
        }
        case searchBook: {
            string searchKey;
            cout << "Enter The Search Key(Title, Isbn): ";
            getline(cin, searchKey);
            Book* b=lib.searchBook(searchKey);
            if(b)
                b->printBookInf();
            else
                cout << "The Book Is Not Found" << endl;
            break;
        }
        case Exit: {
            cout << "Thank You :)" << endl;
            break;
        }
        case addUser: {
            int id;
            string name;
            cout << "Enter Your Name: ";
            getline(cin, name);            
            cout << "Enter Your Id: ";
            cin >> id;
            cin.ignore();
            User* u = lib.findUser(id);
            if (!lib.findUser(id)) {
                User user(name, id);
                lib.addUser(user);
                lib.saveUsers("users.json");
                cout << "The User Added Successfully";
            }
            else {
                cout << "The User Is Already Added" << endl;
            }
            break;
        }
        default: {
            cout << "Inviled Input" << endl;
            break;
        }
        }
    } while (eChoice != Exit);

    lib.saveBooks("books.json");
    lib.saveUsers("users.json");
    
    return 0;
}
