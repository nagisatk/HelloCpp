/*****************************************************
 >    File Name: basic_level_1029.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/1/16 17:10:53
 *****************************************************/

#include<iostream>
#include<cstring>
using namespace std;

bool is_upper(char c) {
    return c >= 'A' && c <= 'Z';
}

bool is_lower(char c) {
    return c >= 'a' && c <= 'z';
}

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

int get_index(char c) {
    if(is_digit(c))
        return c - '0';
    if(is_lower(c))
        return c - 'a' + 10;
    if(is_upper(c))
        return c - 'A' + 10;
    if(c == '_')
        return 36;
}

char get_char(int i) {
    if(i < 10)
        return i + '0';
    if(i < 36)
        return i - 10 + 'A';
    return '_';
}

int main() {
    char should[81];
    char infact[81];
    char badkeys[81] = {};
    cin >> should >> infact;
    int len = strlen(infact);
    int j = 0, x = 0;
    for(int i = 0;i < len;i++, j++) {
        while(should[j] && should[j] != infact[i]) {
            badkeys[x++] = should[j++];
        }
    }
    while(should[j]) {
        badkeys[x++] = should[j++];
    }
    // for(int i = 0;i < 81;i++) {
    //     if(badkeys[i] != 0)
    //         cout << badkeys[i] << ' ';
    // }
    len = strlen(badkeys);
    for(int i = 0;i < len;i++) {
        if(badkeys[i] == 0)
            continue;
        int in1 = get_index(badkeys[i]);
        // cout << badkeys[i] << ' ' << in1 << endl;
        for(int k = i + 1;k < len;k++) {
            if(get_index(badkeys[k]) == in1)
                badkeys[k] = 0;
        }
        cout << get_char(in1);
    }
    
}
