#ifndef BOOK_H
#define BOOK_H

#include <iostream>
using namespace std;

class Book {
public:

    int id;
    string title;
    string author;
    bool isIssued;

    // Constructor
    Book() {
        id = 0;
        title = "";
        author = "";
        isIssued = false;
    }

    Book(int bookId, string bookTitle, string bookAuthor) {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
        isIssued = false;
    }
};

#endif