#ifndef BORROWER_H
#define BORROWER_H

#include <iostream>
using namespace std;

class Borrower {

public:

    int borrowerId;
    string borrowerName;
    int borrowedBookId;

    Borrower() {
        borrowerId = 0;
        borrowerName = "";
        borrowedBookId = -1;
    }

    Borrower(int id, string name) {
        borrowerId = id;
        borrowerName = name;
        borrowedBookId = -1;
    }
};

#endif