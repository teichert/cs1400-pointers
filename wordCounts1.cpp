// Purpose: Demonstrate pointers and C-Strings in the C++ by reading
// words from a text file, sorting them, and then printing word counts
// without using <string>.  (In this version, we also do not use
// <cstring>)

// Author: Adam Teichert and Snow College CS 1400 class Spring 2020
// Date: Started April 15, 2020


#include <cassert>
#include <iostream>
using std::cout;
using std::endl;

// TODO: test and write stringLength
// TODO: test and write compareCStrings
// TODO: test and write copyCString
// TODO: test and write nextWord
// TODO: test and write readWords
// TODO: test and write freeWords
// TODO: test and write sortWords
// TODO: test and write countWords
// TODO: write main

// return the length of the given c-string
int stringLength(const char* s);

void testDriver() {
    assert(stringLength("") == 0);
    assert(stringLength("hi") == 2);
    assert(stringLength(" ") == 1);
    assert(stringLength("0") == 1);
    assert(stringLength("I") == 1);
    assert(stringLength("hello world") == 11);
    char str[] = {'h', 'i', '\0'};
    assert(stringLength(str) == 2);
    const char* str2 = "hi";
    assert(stringLength(str2) == 2);
    cout << "All tests passed." << endl;
}

int stringLength(const char* s) {
    int length = 0;
    // increment length until we find the null terminating character
    for (int i = 0; s[i] != '\0'; i++) {
        length++;
    }
    return length;
}


int main() {
    testDriver();
    return 0;
}
