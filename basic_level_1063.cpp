/*****************************************************
 >    File Name: basic_level_1063.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/2/15 9:13:09
 *****************************************************/

#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main() {
    int n, r, v;
    double mod, maxmod=0;
    cin >> n;
    while(n--) {
        cin >> r >> v;
        mod = sqrt(r*r + v*v);
        if(mod > maxmod)
            maxmod = mod;
    }
    cout << fixed << setprecision(2) << maxmod;
}
