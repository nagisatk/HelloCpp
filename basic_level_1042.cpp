/*****************************************************
 >    File Name: basic_level_1042.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/2/4 10:57:54
 *****************************************************/

#include<iostream>
#define is_upper(c) (c) >= 'A' && (c) <= 'Z'
#define is_lower(c) (c) >= 'a' && (c) <= 'z'
#define index(c) (c) - 'A' + 'a'
using namespace std;

int main() {
    char c;
    int counts[128] = {};
    while((c = cin.get()) != '\n') {
        if(is_upper(c))
            counts[index(c)]++;
        else if(is_lower(c))
            counts[c]++;
    }
    int ch = 0, r = 0;
    for(int i = 'a'; i <= 'z'; i ++) {
        if(counts[i] > r) {
            r = counts[i];
            ch = i;
        }
    }
    cout << char(ch) << ' ' << r;
}
