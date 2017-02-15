/*****************************************************
 >    File Name: basic_level_1064.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/2/15 9:21:51
 *****************************************************/

#include<iostream>
using namespace std;

int main() {
    int n, t, cnt = 0, index = 0, res[37] = {};
    cin >> n;
    while(n--) {
        cin >> t;
        while(t) {
            index += t%10;
            t /= 10;
        }
        if(!res[index]) {
            cnt++;
            res[index] = 1;
        }
        index = 0;
    }
    cout << cnt << '\n';
    while(res[++index] == 0);
    cout << index;
    for(index++; index<37; index++)
        if(res[index])
            cout << ' ' << index;
}
