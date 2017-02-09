/*****************************************************
 >    File Name: basic_level_1046.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/2/7 21:15:16
 *****************************************************/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    // n *= 4;
    // int res[n], a = 0, b = 0, t;
    // for(int i = 0; i < n; i++) {
    //     cin >> res[i];
    //     // cout << res[i] << '\n';
    // }
    // for(int i = 0; i<n; i+=4) {
    //     // cout << res[i] << ' '  << res[i+1] << ' '  << res[i+2] << ' '  << res[i+3] << ' '  << endl;
    //     t = res[i] + res[i+2];
    //     if(t != res[i+1] && t == res[i+3])
    //         a++;
    //     else if(t != res[i+3] && t == res[i+1])
    //         b++;
    // }
    // cout << a << ' ' << b << endl;;
    int a = 0, b = 0, a1, a2, b1, b2;
    for(int i = 0; i < n; i ++) {
        cin >> a1 >> a2 >> b1 >> b2;
        if(a2 != a1 + b1 && b2 == a1 + b1)
            a++;
        if(b2 != a1 + b1 && a2 == a1 + b1)
            b++;
    }
    cout << a << ' ' << b;
}
