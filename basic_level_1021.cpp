/*****************************************************
 >    File Name: basic_level_1021.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/1/14 21:17:07
 *****************************************************/

#include<iostream>
using namespace std;

int main() {
    char* digits = new char[1001];
    cin >> digits;
    int count[10] = {};
    while(*digits)
        count[*digits++ - '0']++;
    for(int i = 0;i < 10;i ++)
        if(count[i])
            cout << i << ':' << count[i] << '\n';

}
