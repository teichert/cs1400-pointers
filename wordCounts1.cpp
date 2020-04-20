// Purpose: Demonstrate pointers and C-Strings in the C++ by reading
// words from a text file, sorting them, and then printing word counts
// without using <string>.  (In this version, we also do not use
// <cstring>)

// Author: Adam Teichert and Snow College CS 1400 class Spring 2020
// Date: Started April 15, 2020

#include <cassert> // <assert.h>
#include <cstring> // <string.h> strlen
#include <iostream>
using std::cout;
using std::endl;

// xTODO: test and write stringLength (strlen)
// xTODO: test and write compareCStrings (strcmp)
// xTODO: test and write compareCStrings2 ('B' < 'b' < 'C' < 'c')
// TODO: test and write copyCString (strcpy)
// TODO: test and write nextWord (cin >> word)
// TODO: test and write readWords
// TODO: test and write freeWords
// TODO: test and write sortWords
// TODO: test and write countWords
// TODO: write main

// return true is 'a' points to the same string of
// characters as 'b' (you can strcmp from <cstring>)
// assert(streq("test", "test"));
// assert(!streq("test", "test2"));
bool streq(const char* a, const char* b);

// return the length of the given c-string
// equivalent to strlen in <cstring> header
int stringLength(const char* s);

// copy the characters from src to dest
// (until and including the NULL)
// equivalent to strcpy in <cstring> header
void copyCString(char* dest, const char* src);


// return negative number if lhs should come earlier than rhs (in a sorted list)
// return positive number if lhs should come later than rhs
// return 0 if lhs is the same as rhs
int compareCStrings(const char* lhs, const char* rhs);

// tweaked definition of ordering: ('B' < 'b' < 'C' < 'c')
// return negative number if lhs should come earlier than rhs (in a sorted list)
// return positive number if lhs should come later than rhs
// return 0 if lhs is the same as rhs
int compareCStrings2(const char* lhs, const char* rhs);

// test our intcmp function
void test_intcmp();

void testDriver() {
    test_intcmp();
    { // compareCStrings2
        // same string should give 0
        assert(compareCStrings2("test", "test") == 0);
        char str1[] = {'h', 'i', '\0', '!'};
        char str2[] = {'h', 'i', '\0'};
        assert(compareCStrings2(str1, str2) == 0);
        assert(compareCStrings2("apple", "bob") < 0);
        assert(compareCStrings2("bob", "apple") > 0);
        assert(compareCStrings2("Test", "test") < 0);
        assert(compareCStrings2("Test", "apple") > 0);
    }
    { // compareCStrings
        // same string should give 0
        assert(compareCStrings("test", "test") == 0);
        char str1[] = {'h', 'i', '\0', '!'};
        char str2[] = {'h', 'i', '\0'};
        assert(compareCStrings(str1, str2) == 0);
        assert(compareCStrings("apple", "bob") < 0);
        assert(compareCStrings("bob", "apple") > 0);
        assert(compareCStrings("Test", "test") < 0);
        assert(compareCStrings("Test", "apple") < 0);
    }
    { // strcmp
        // same string should give 0
        assert(strcmp("test", "test") == 0);
        char str1[] = {'h', 'i', '\0', '!'};
        char str2[] = {'h', 'i', '\0'};
        assert(strcmp(str1, str2) == 0);
        assert(strcmp("apple", "bob") < 0);
        assert(strcmp("bob", "apple") > 0);
        assert(strcmp("Test", "test") < 0);
        assert(strcmp("Test", "apple") < 0);
    }
    { // test stringLength
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
    }

    { // implemented in <cstring> as strlen
        assert(strlen("") == 0);
        assert(strlen("hi") == 2);
        assert(strlen(" ") == 1);
        assert(strlen("0") == 1);
        assert(strlen("I") == 1);
        assert(strlen("hello world") == 11);
        char str[] = {'h', 'i', '\0'};
        assert(strlen(str) == 2);
        const char* str2 = "hi";
        assert(strlen(str2) == 2);
    }
    {
        assert(streq("test", "test"));
        assert(!streq("test", "test2"));
        assert(!streq("test", "Test"));
    }
    {
         char str1[] = {'h', 'i', '\0', '!'};
         char str2[10] = "blah";
         assert(streq(str1, "hi"));
         copyCString(str2, str1);
         assert(streq(str1, "hi"));
         assert(streq(str2, "hi"));
    }
    cout << "All tests passed." << endl;
}

bool streq(const char* a, const char* b) {
    return strcmp(a, b) == 0;    
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

void copyCString(char* dest, const char* src) {
 // TODO: implement this
}

int compareCStrings(const char* lhs, const char* rhs) {
    // walk along letter-by-letter:
    int i = 0; // current index we are comparing
    while (true) {
        if (lhs[i] < rhs[i]) {
            return -1; // return negative (because lhs should come first)
        } else if (lhs[i] > rhs[i]) {
            return 1; // return negative (because lhs should come first)
        } else if (lhs[i] == '\0'){
            // both strings are the same up now and both have ended
            return 0;
        }
        i++;
    }
}


int compareCStrings2(const char* lhs, const char* rhs) {
    // walk along letter-by-letter:
    int i = 0; // current index we are comparing
    // assert(isupper('A'));
    // assert(!isupper('a'));
    // assert(!isspace('a'));
    // assert(isspace(' '));
    // assert(isspace('\t'));
    // assert(isspace('\n'));
    // assert(toupper('a') == 'A');
    // assert(tolower('A') == 'a');
    while (true) {
        if (tolower(lhs[i]) < tolower(rhs[i])) {
            return -1; // return negative (because lhs should come first)
        } else if (tolower(lhs[i]) > tolower(rhs[i])) {
            return 1; // return negative (because lhs should come first)
        } else if (tolower(lhs[i]) == '\0'){
            // both strings are the same up now and both have ended
            return 0;
        } else if (lhs[i] < rhs[i]) {
            return -1;
        } else if (lhs[i] > rhs[i]) {
            return 1;
        } 
        i++;
    }
}


// alternative implementation
// int intcmp(int lhs, int rhs) {
//     return lhs - rhs;
// }

int intcmp(int lhs, int rhs) {
    if (lhs < rhs) {
        return -1;
    } else if (lhs > rhs) {
        return 1;
    } else {
        return 0;
    }
}

void test_intcmp() {
    // 15 < 20
    assert(intcmp(15, 20) < 0);
    assert(strcmp("15", "20") < 0);
    // 20 > 15
    assert(intcmp(20, 15) > 0);
    assert(strcmp("20", "15") > 0);
    // 10 == 10
    assert(intcmp(10, 10) == 0);
    assert(strcmp("10", "10") == 0);
    // remember that strcmp won't pad the left
    assert(intcmp(5, 20) < 0);
    assert(strcmp("5", "20") > 0);

}    