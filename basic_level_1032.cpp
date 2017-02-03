/*****************************************************
 >    File Name: basic_level_1032.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/1/16 21:15:14
 *****************************************************/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int grade[n+1] = {};
    for(int i = 0;i < n;i++) {
        int x, g;
        cin >> x >> g;
        grade[x] += g;
    }
    int max = 0, index = 0;
    for(int i = 1;i < n + 1;i++) {
        if(grade[i] > max) {
            max = grade[i];
            index = i;
        }
    }
    cout << index << ' ' << max;
}
