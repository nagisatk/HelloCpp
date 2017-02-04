/*****************************************************
 >    File Name: basic_level_1040.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/2/3 17:10:07
 *****************************************************/

#include<iostream>
#include<vector>
using namespace std;

int main() {
    long long count = 0;
    char input[100001];
    cin >> input;
    int i = 0;
    long long p = 0, a = 0;
    while(input[i]) {
        while(input[i]=='P') {
            p++;
            i++;
        }
        while(input[i]=='A') {
            a+=p;
            i++;
        }
        while(input[i]=='T') {
            count += a;
            i++;
        }
    }
    cout << count%1000000007;
}
