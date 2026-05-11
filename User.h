#ifndef USER_H
#define USER_H

#include <iostream>
using namespace std;

class User {

public:

    string username;
    string password;
    string role;

    User() {
        username = "";
        password = "";
        role = "";
    }

    User(string u, string p, string r) {
        username = u;
        password = p;
        role = r;
    }
};

#endif