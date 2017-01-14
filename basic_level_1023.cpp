/*****************************************************
 >    File Name: basic_level_1023.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/1/14 21:58:28
 *****************************************************/

#include<iostream>
using namespace std;

int main() {
    int numbers[10];
    for(int i = 0;i < 10; i ++)
        cin >> numbers[i];
    for(int i = 1;i < 10;i ++) {
        if(numbers[i]) {
            cout << i;
            numbers[i]--;
            break;
        }
    }
    for(int i = 0;i < 10;i ++)
        while(numbers[i]--)
            cout << i;
}
