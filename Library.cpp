
// Library.cpp  press Ctrl + Shift + B


#include <iostream>
#include <vector>
#include <fstream>


#include "User.h"
#include "Borrower.h"
#include "Book.h"

using namespace std;

// Vector to store books
vector<Book> books;
// Vector to store borrowers
vector<Borrower> borrowers;
// Vector to store users
vector<User> users;




// ===============================
// SAVE BOOKS TO FILE
// ===============================
void saveBooksToFile() {

    ofstream file("books.txt");

    if(!file) {

        cout << "\nError Opening File.\n";
        return;
    }

    for(int i = 0; i < books.size(); i++) {

        file << books[i].id << endl;
        file << books[i].title << endl;
        file << books[i].author << endl;
        file << books[i].isIssued << endl;
    }

    file.close();
}


// ==============================
// LOAD BOOKS FROM FILE
// ===============================
void loadBooksFromFile() {

    ifstream file("books.txt");

    ///cout << "\nLoading books from file...\n";

    if(!file) {

        return;
    }

    books.clear();

    int id;
    string title;
    string author;
    bool isIssued;

    while(file >> id) {

        file.ignore();

        getline(file, title);
        getline(file, author);

        file >> isIssued;

        file.ignore();
        
        Book newBook(id, title, author);

        newBook.isIssued = isIssued;

        books.push_back(newBook);
    }

    file.close();
}


// ===============================
// SAVE BORROWERS
// ===============================
void saveBorrowersToFile() {

    ofstream file("borrowers.txt");

    if(!file) {

        cout << "\nError Opening Borrowers File.\n";
        return;
    }

    for(int i = 0; i < borrowers.size(); i++) {

        file << borrowers[i].borrowerId << endl;

        file << borrowers[i].borrowerName << endl;

        file << borrowers[i].borrowedBookId << endl;
    }

    file.close();
}


// ===============================
// LOAD borrower
// ===============================
void loadBorrowersFromFile() {

    ifstream file("borrowers.txt");

    if(!file) {

        return;
    }

    borrowers.clear();

    int id;
    string name;
    int borrowedBookId;

    while(file >> id) {

        file.ignore();

        getline(file, name);

        file >> borrowedBookId;

        file.ignore();

        Borrower newBorrower(id, name);

        newBorrower.borrowedBookId =
            borrowedBookId;

        borrowers.push_back(newBorrower);
    }

    file.close();
}




// ===============================
// ADD BOOK
// ===============================
void addBook() {

    int id;
    string title;
    string author;

    cout << "\n========== ADD BOOK ==========\n";

    cout << "Enter Book ID: ";
    cin >> id;

    cin.ignore();

    cout << "Enter Book Title: ";
    getline(cin, title);

    cout << "Enter Author Name: ";
    getline(cin, author);

    // Create object
    Book newBook(id, title, author);

    // Add to vector
    books.push_back(newBook);

    saveBooksToFile();

    cout << "\nBook Added Successfully!\n";
}

// ===============================
// VIEW BOOKS
// ===============================
void viewBooks() {

    cout << "\n========== BOOK LIST ==========\n";

    if(books.empty()) {
        cout << "No books available.\n";
        return;
    }

    for(int i = 0; i < books.size(); i++) {

        cout << "\nBook " << i + 1 << endl;

        cout << "ID       : " << books[i].id << endl;
        cout << "Title    : " << books[i].title << endl;
        cout << "Author   : " << books[i].author << endl;

        if(books[i].isIssued)
            cout << "Status   : Issued\n";
        else
            cout << "Status   : Available\n";
    }
}

// ===============================
// SEARCH BOOK
// ===============================
void searchBook() {

    int searchId;
    bool found = false;

    cout << "\nEnter Book ID to Search: ";
    cin >> searchId;

    for(int i = 0; i < books.size(); i++) {

        if(books[i].id == searchId) {

            cout << "\nBook Found!\n";

            cout << "ID       : " << books[i].id << endl;
            cout << "Title    : " << books[i].title << endl;
            cout << "Author   : " << books[i].author << endl;

            found = true;
            break;
        }
    }

    if(!found) {
        cout << "\nBook Not Found.\n";
    }
}

// ===============================
// DELETE BOOK
// ===============================
void deleteBook() {

    int deleteId;
    bool found = false;

    cout << "\nEnter Book ID to Delete: ";
    cin >> deleteId;

    for(int i = 0; i < books.size(); i++) {

        if(books[i].id == deleteId) {

            books.erase(books.begin() + i);

            saveBooksToFile();

            cout << "\nBook Deleted Successfully!\n";

            found = true;
            break;
        }
    }

    if(!found) {
        cout << "\nBook Not Found.\n";
    }
}

// ===============================
// ADD BORROWER
// ===============================

void addBorrower() {

    int id;
    string name;

    cout << "\n========== ADD BORROWER ==========\n";

    cout << "Enter Borrower ID: ";
    cin >> id;

    cin.ignore();

    cout << "Enter Borrower Name: ";
    getline(cin, name);

    Borrower newBorrower(id, name);

    borrowers.push_back(newBorrower);

    saveBorrowersToFile();

    cout << "\nBorrower Added Successfully!\n";
}


// ===============================
// VIEW BORROWERS
// ===============================
void viewBorrowers() {

    cout << "\n========== BORROWER LIST ==========\n";

    if(borrowers.empty()) {

        cout << "No borrowers available.\n";
        return;
    }

    for(int i = 0; i < borrowers.size(); i++) {

        cout << "\nBorrower " << i + 1 << endl;

        cout << "Borrower ID   : "
             << borrowers[i].borrowerId << endl;

        cout << "Name          : "
             << borrowers[i].borrowerName << endl;

        if(borrowers[i].borrowedBookId == -1)
            cout << "Borrowed Book : None\n";
        else
            cout << "Borrowed Book ID : "
                 << borrowers[i].borrowedBookId << endl;
    }
}


// ===============================
// ISSUE BOOK
// ===============================
void issueBook() {

    int borrowerId;
    int bookId;

    bool borrowerFound = false;
    bool bookFound = false;

    cout << "\nEnter Borrower ID: ";
    cin >> borrowerId;

    cout << "Enter Book ID: ";
    cin >> bookId;

    // Find borrower
    for(int i = 0; i < borrowers.size(); i++) {

        if(borrowers[i].borrowerId == borrowerId) {

            borrowerFound = true;

            // Find book
            for(int j = 0; j < books.size(); j++) {

                if(books[j].id == bookId) {

                    bookFound = true;

                    if(books[j].isIssued) {

                        cout << "\nBook Already Issued.\n";
                        return;
                    }

                    books[j].isIssued = true;

                    borrowers[i].borrowedBookId = bookId;

                    saveBooksToFile();
                    saveBorrowersToFile();

                    cout << "\nBook Issued Successfully!\n";

                    return;
                }
            }
        }
    }

    if(!borrowerFound)
        cout << "\nBorrower Not Found.\n";

    else if(!bookFound)
        cout << "\nBook Not Found.\n";
}


// ===============================
// RETURN BOOK
// ===============================
void returnBook() {

    int borrowerId;

    bool borrowerFound = false;

    cout << "\nEnter Borrower ID: ";
    cin >> borrowerId;

    for(int i = 0; i < borrowers.size(); i++) {

        if(borrowers[i].borrowerId == borrowerId) {

            borrowerFound = true;

            int borrowedBookId =
                borrowers[i].borrowedBookId;

            if(borrowedBookId == -1) {

                cout << "\nNo book issued.\n";
                return;
            }

            // Find book
            for(int j = 0; j < books.size(); j++) {

                if(books[j].id == borrowedBookId) {

                    books[j].isIssued = false;

                    borrowers[i].borrowedBookId = -1;

                    saveBooksToFile();
                    saveBorrowersToFile();

                    cout << "\nBook Returned Successfully!\n";

                    return;
                }
            }
        }
    }

    if(!borrowerFound)
        cout << "\nBorrower Not Found.\n";
}



// ===============================
// INITIALIZE USERS
// ===============================
void initializeUsers() {

    User admin("ad", "12", "Admin");

    users.push_back(admin);
}


// ===============================
// LOGIN FUNCTION
// ===============================
bool login() {

    string username;
    string password;

    cout << "\n========== LOGIN ==========\n";

    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;

    for(int i = 0; i < users.size(); i++) {

        if(users[i].username == username &&
           users[i].password == password) {

            cout << "\nLogin Successful!\n";

            cout << "Welcome "
                 << users[i].role << endl;

            return true;
        }
    }

    cout << "\nInvalid Username or Password.\n";

    return false;
}


// ===============================
// SEARCH BOOK BY TITLE
// ===============================
void searchBookByTitle() {

    string searchTitle;

    bool found = false;

    cin.ignore();

    cout << "\nEnter Book Title: ";

    getline(cin, searchTitle);

    for(int i = 0; i < books.size(); i++) {

        if(books[i].title == searchTitle) {

            cout << "\nBook Found!\n";

            cout << "ID       : "
                 << books[i].id << endl;

            cout << "Title    : "
                 << books[i].title << endl;

            cout << "Author   : "
                 << books[i].author << endl;

            found = true;
        }
    }

    if(!found) {

        cout << "\nBook Not Found.\n";
    }
}


// ===============================
// SEARCH BOOK BY AUTHOR
// ===============================
void searchBookByAuthor() {

    string searchAuthor;

    bool found = false;

    cin.ignore();

    cout << "\nEnter Author Name: ";

    getline(cin, searchAuthor);

    for(int i = 0; i < books.size(); i++) {

        if(books[i].author == searchAuthor) {

            cout << "\nBook Found!\n";

            cout << "ID       : "
                 << books[i].id << endl;

            cout << "Title    : "
                 << books[i].title << endl;

            cout << "Author   : "
                 << books[i].author << endl;

            found = true;
        }
    }

    if(!found) {

        cout << "\nNo Books Found.\n";
    }
}


// ===============================
// UPDATE BOOK
// ===============================
void updateBook() {

    int updateId;

    bool found = false;

    cout << "\nEnter Book ID to Update: ";

    cin >> updateId;

    cin.ignore();

    for(int i = 0; i < books.size(); i++) {

        if(books[i].id == updateId) {

            found = true;

            cout << "\nEnter New Title: ";

            getline(cin, books[i].title);

            cout << "Enter New Author: ";

            getline(cin, books[i].author);

            saveBooksToFile();

            cout << "\nBook Updated Successfully!\n";

            return;
        }
    }

    if(!found) {

        cout << "\nBook Not Found.\n";
    }
}



