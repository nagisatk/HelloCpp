/*****************************************************
 >    File Name: basic_level_1017.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/1/13 20:20:01
 *****************************************************/

#include<iostream>
using namespace std;

int main() {
    char di[1001];
    int d;
    cin >> di >> d;
    int r = 0, i = 0;
    bool flag = false;
    while(di[i]) {
        int t = di[i] - '0' + r * 10;
        int q = t / d;
        if(flag)
            cout << q;
        else if(q > 0) {
            cout << q;
            flag = true;
        }
        r = t % d;
        i ++;
    }
    if(!flag)
        cout << 0;
    cout << ' ' << r;
}
