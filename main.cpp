#include <iostream>

// #include "Library.cpp"
using namespace std;

// Function Declarations
bool login();
void initializeUsers();
void addBook();
void viewBooks();
void searchBook();
void deleteBook();
void addBorrower();
void viewBorrowers();
void issueBook();
void returnBook();
void loadBooksFromFile();
void loadBorrowersFromFile();
void searchBookByTitle();
void searchBookByAuthor();
void updateBook();

void showMainMenu();

int main() {

   int choice;

    cout << "\n========================================\n";
    cout << "     WELCOME TO LIBRARY SYSTEM\n";
    cout << "========================================\n";

    // Initialize default users
    initializeUsers();

    loadBooksFromFile();
    
    loadBorrowersFromFile();

    // Login check
    if(!login()) {

        cout << "\nAccess Denied.\n";

        return 0;
    }

    do {

        showMainMenu();

        if(!(cin >> choice)) {

            cin.clear();

            cin.ignore(1000, '\n');

            cout << "\nInvalid Input!\n";

            continue;
        }

        switch(choice) {

            case 1:
                addBook();
                break;

            case 2:
                viewBooks();
                break;

            case 3:
                searchBook();
                break;

            case 4:
                deleteBook();
                break;

            case 5:
                searchBookByTitle();
                break;

            case 6:
                searchBookByAuthor();
                break;

            case 7:
                updateBook();
                break;

            case 8:
                addBorrower();
                break;

            case 9:
                viewBorrowers();
                break;

            case 10:
                issueBook();
                break;

            case 11:
                returnBook();
                break;

            case 12:
                cout << "\nExiting Program...\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 12);

    return 0;
}

void showMainMenu() {

    cout << "\n========================================\n";
    cout << "        LIBRARY MANAGEMENT SYSTEM\n";
    cout << "========================================\n";

    cout << "\n----------- BOOK MANAGEMENT ------------\n";

    cout << "1.  Add Book\n";
    cout << "2.  View Books\n";
    cout << "3.  Search Book By ID\n";
    cout << "4.  Delete Book\n";
    cout << "5.  Search Book By Title\n";
    cout << "6.  Search Book By Author\n";
    cout << "7.  Update Book\n";

    cout << "\n--------- BORROWER MANAGEMENT ----------\n";

    cout << "8.  Add Borrower\n";
    cout << "9.  View Borrowers\n";
    cout << "10. Issue Book\n";
    cout << "11. Return Book\n";

    cout << "\n----------------------------------------\n";

    cout << "12. Exit\n";

    cout << "\nEnter your choice: ";
}