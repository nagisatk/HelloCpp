/*****************************************************
 >    File Name: basic_level_1019.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/1/14 16:44:30
 *****************************************************/

#include<iostream>
using namespace std;

int make_max(char* digs) {
    int max = 0;
    for(int i = 9;i >= 0;i --) {
        int t = digs[i];
        while(t--) {
            cout << i;
            max = max * 10 + i;
        }
    }
    return max;
}

int make_min(char* digs) {
    int min = 0;
    for(int i = 0;i < 10;i ++) {
        int t = digs[i];
        while(t--) {
            cout << i;
            min = min * 10 + i;
        }
    }
    return min;
}

void analyse_numbers(int n, char* digs) {
    while(n < 1000)
        n = n * 10;
    while(n) {
        digs[n % 10]++;
        n = n / 10;
    }
}

int main() {
    int number;
    cin >> number;
    do {
        char digs[10] = {};
        analyse_numbers(number, digs);
        int max = make_max(digs);
        cout << " - ";
        int min = make_min(digs);
        number = max - min;
        cout << " = ";
        if(number == 0)
            cout << "000";
        else if(number < 1000)
            cout << 0;
        cout << number << '\n';
    }while(number != 6174 && number != 0);
}
