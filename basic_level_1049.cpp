/*****************************************************
 >    File Name: basic_level_1049.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/2/8 15:42:03
 *****************************************************/

#include<iostream>
#include<iomanip>
using namespace std;

int main() {
    int n;
    cin >> n;
    double seq[n], sum = 0;
    for(int i=0; i<n; i++) {
        cin >> seq[i];
        sum += seq[i]*(i+1)*(n-i);
    }
    cout << fixed << setprecision(2) << sum << endl;
}
