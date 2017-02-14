/*****************************************************
 >    File Name: basic_level_1056.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/2/13 17:56:20
 *****************************************************/

#include<iostream>
using namespace std;

int main() {
    int n, t, sum = 0;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> t;
        sum += t;
    }
    n = 10*(n-1) + n-1;
    cout << n*sum << endl;
}
