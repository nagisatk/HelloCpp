/*****************************************************
 >    File Name: basic_level_1062.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/2/14 19:35:52
 *****************************************************/

#include<iostream>
#include<cmath>
using namespace std;

int max_common_divisor(int a, int b) {
    if (a % b == 0)
        return abs(b);
    return max_common_divisor(b, a % b);
}

int swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main() {
    int m1, m2, d1, d2, d, l = 1, r = 0, flg = 0;
    char t;
    cin >> m1 >> t >> d1 >> m2 >> t >> d2 >> d;
    // cout << m1 << t << d1 << ' ' << m2 << t << d2 << "  " << d << endl;
    if(m1*d2 > m2*d1) {
        swap(&m1, &m2);
        swap(&d1, &d2);
    }
    // cout << m1 << t << d1 << ' ' << m2 << t << d2 << "  " << d << endl;
    // if(m1*d2 < m2*d1) {
        // l = m1*d/d1;
        // r = m2*d/d2;
        // if(l*d1 < m1*d)
            // l++;
        // if(r*d2 <= m2*d)
            // r++;
    // } else {
        // l = m2*d/d2;
        // r = m1*d/d1;
        // if(l*d2 < m2*d)
            // l++;
        // if(r*d1 <= m1*d)
            // r++;
    // }
    while(l*d1 <= m1*d) l++;
    r = d;
    while(r*d2 > m2*d) r--;
    while(l<=r) {
        if(max_common_divisor(l, d) == 1)
            if(!flg) {
                cout << l << '/' << d;
                flg = 1;
            } else
                cout << ' ' << l << '/' << d;
        l++;
    }
    // while(max_common_divisor(d, l) != 1)
        // l++;
    // cout << l << '/' << d;
    // for(l++; l<r; l++)
        // if(max_common_divisor(d, l) == 1)
            // cout << ' ' << l << '/' << d;
}
