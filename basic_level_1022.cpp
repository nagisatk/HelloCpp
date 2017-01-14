/*****************************************************
 >    File Name: basic_level_1022.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/1/14 21:31:11
 *****************************************************/

#include<iostream>
using namespace std;

int main() {
    int a, b, scale;
    cin >> a >> b >> scale;
    a += b;
    if(a == 0) {
        cout << 0;
        return 0;
    }
    int res[32] = {};
    int i = 0;
    while(a) {
        res[i++] = a % scale;
        a /= scale;
    }
    for(int j = i - 1;j >= 0;j --)
        cout << res[j];
}
