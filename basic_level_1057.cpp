/*****************************************************
 >    File Name: basic_level_1057.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/2/13 18:01:02
 *****************************************************/

#include<iostream>
#define is_upper(c) (c)>='A' && (c)<='Z'
#define is_lower(c) (c)>='a' && (c)<='z'
using namespace std;

int get_number(char c) {
    if(is_upper(c))
        return c-'A'+1;
    else if(is_lower(c))
        return c-'a'+1;
    else return 0;
}

int main() {
    char c;
    int sum = 0;
    while((c = cin.get()) != '\n')
        sum += get_number(c);
    int one = 0, zero = 0;
    while(sum) {
        if(sum%2) one++;
        else      zero++;
        sum /= 2;
    }
    cout << zero << ' ' << one;
}
