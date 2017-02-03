/*****************************************************
 >    File Name: basic_level_1033.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/1/16 21:26:59
 *****************************************************/

#include<iostream>
#define is_upper(c) (c) >= 'A' && (c) <= 'Z'
using namespace std;

int main() {
    int keyboard[128] = {};
    // char badkeys[128] = {};
    char should[100001];
    int i = 0;
    for(char ch = cin.get();ch != '\n';ch = cin.get()) {
        if(ch == '+')
            for(int j = 'A'; j <= 'Z';j ++)
                keyboard[j] = 1;
        else if(is_upper(ch)) {
            keyboard[ch] = 1;
            keyboard[ch - 'A' + 'a'] = 1;
        } else
            keyboard[ch] = 1;
    }
    cin >> should;
    // i = 0;
    // while(badkeys[i]) {
    //     // cout << badkeys[i] << endl;
    //     if(badkeys[i] == '+') {
    //         for(int j = 'A';j <= 'Z';j++) {
    //             keyboard[j] = 1;
    //         }
    //     } else if(is_upper(badkeys[i])) {
    //         keyboard[badkeys[i]] = 1;
    //         keyboard[badkeys[i] - 'A' + 'a'] = 1;
    //     } else {
    //         keyboard[badkeys[i]] = 1;
    //     }
    //     i ++;
    // }
    // i = 0;
    while(should[i]) {
        if(!keyboard[should[i]])
            cout << should[i];
        i++;
    }
    cout << '\n';
    // for(int k = 0;k < 128;k++) {
        // cout << char(k) << endl;
    // }

}
