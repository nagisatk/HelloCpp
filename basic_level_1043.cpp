/*****************************************************
 >    File Name: basic_level_1043.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/2/4 11:17:26
 *****************************************************/

#include<iostream>
using namespace std;

int main() {
    int P = 0, A = 0, T = 0, e = 0, s = 0, t = 0;
    int pat[6] = {};
    char c;
    while((c = cin.get()) != '\n') {
        switch(c) {
            case 'A': pat[1]++;break;
            case 'P': pat[0]++;break;
            case 'T': pat[2]++;break;
            case 'e': pat[3]++;break;
            case 's': pat[4]++;break;
            case 't': pat[5]++;break;
        }
    }
    while(pat[0]+pat[1]+pat[2]+pat[3]+pat[4]+pat[5]) {
        switch(0) {
            case 0: if(pat[0]) { cout << 'P';pat[0]--; }
            case 1: if(pat[1]) { cout << 'A';pat[1]--; }
            case 2: if(pat[2]) { cout << 'T';pat[2]--; }
            case 3: if(pat[3]) { cout << 'e';pat[3]--; }
            case 4: if(pat[4]) { cout << 's';pat[4]--; }
            case 5: if(pat[5]) { cout << 't';pat[5]--; }
        }
    }
}
