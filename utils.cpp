//
// Created by Umut on 12.11.2019.
//

#include "utils.h"

char utils::readSelection(const string &letter) {
    string s;
    do {
        cin >> s;
        if (s.length() > 1
            || s.find_first_not_of(letter) != string::npos
                )
            cout << "Wrong Selection Try again";
        else
            break;
    } while (true);
    return s[0];
}