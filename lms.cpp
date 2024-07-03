//Library Management System
//Bimarsha Shrestha
//ACE079BCT020
#include <iostream>
#include <string>

using namespace std;

// Maximum number of books the library can hold
const int MAX_BOOKS = 100;

// Book class to represent a book
class Book {
public:
    string title;
    string author;
    int year;

    // Default constructor
    Book() : title(""), author(""), year(0) {}

    Book(string t, string a, int y) : title(t), author(a), year(y) {}
};

// Library class to manage books
class Library {
private:
    Book books[MAX_BOOKS]; // Array to store books
    int numBooks; // Current number of books in the library

public:
    Library() : numBooks(0) {}

    // Add a book to the library
    void addBook(const Book& book) {
        if (numBooks < MAX_BOOKS) {
            books[numBooks++] = book;
            cout << "Book added successfully." << endl;
        } else {
            cout << "Library is full. Cannot add more books." << endl;
        }
    }

    // Display all books in the library
    void displayBooks() {
        if (numBooks == 0) {
            cout << "No books in the library." << endl;
        } else {
            cout << "Library Books:" << endl;
            for (int i = 0; i < numBooks; ++i) {
                cout << "Title: " << books[i].title << ", Author: " << books[i].author << ", Year: " << books[i].year << endl;
            }
        }
    }

    // Search for a book by title
    void searchBook(const string& title) {
        bool found = false;
        for (int i = 0; i < numBooks; ++i) {
            if (books[i].title == title) {
                cout << "Book found:" << endl;
                cout << "Title: " << books[i].title << ", Author: " << books[i].author << ", Year: " << books[i].year << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Book not found." << endl;
        }
    }
};

int main() {
    Library library;
    int choice;
    string title, author;
    int year;

    do {
        cout << "\nLibrary Management System" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Display All Books" << endl;
        cout << "3. Search Book" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter book title: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, title);
                cout << "Enter book author: ";
                getline(cin, author);
                cout << "Enter publication year: ";
                cin >> year;
                library.addBook(Book(title, author, year));
                break;
            case 2:
                library.displayBooks();
                break;
            case 3:
                cout << "Enter book title to search: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, title);
                library.searchBook(title);
                break;
            case 4:
                cout << "Program Exited Successfully." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
