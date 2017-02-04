/*****************************************************
 >    File Name: basic_level_1038.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/2/3 12:25:17
 *****************************************************/

#include<iostream>
using namespace std;

int main() {
    int n, t;
    cin >> n;
    int grades[101] = {};
    int counts[n] = {};
    for(int i = 0; i < n; i++) {
        cin >> t;
        grades[t]++;
    }
    cin >> n;
    for(int i = 0;i < n;i++) {
        cin >> t;
        if(i)
            cout << ' ';
        cout << grades[t];
    }
}
