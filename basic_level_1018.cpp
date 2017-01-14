/*****************************************************
 >    File Name: basic_level_1018.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/1/13 21:28:20
 *****************************************************/

#include<iostream>
using namespace std;

int main() {
    int a[3] = {};
    int awin['J'+1] = {};
    int bwin['J'+1] = {};
    int ab = 0, ac = 0, aj = 0;
    int bb = 0, bc = 0, bj = 0;
    int times;
    cin >> times;
    while(times--) {
        char ges1,ges2;
        cin >> ges1 >> ges2;
        int r = ges1 - ges2;
        switch(r) {
            case 0:
                a[1] ++;
                break;
            case -1:    //B C
                a[0] ++;
                // awin['B'] ++;
                ab ++;
                break;
            case -7:    //C J
                a[0] ++;
                // awin['C'] ++;
                ac ++;
                break;
            case  8:    //J B
                a[0] ++;
                // awin['J'] ++;
                aj ++;
                break;
            case  1:    //C B
                a[2] ++;
                // bwin['B'] ++;
                bb ++;
                break;
            case  7:    //J C
                a[2] ++;
                // bwin['C'] ++;
                bc ++;
                break;
            case -8:    //B J
                a[2] ++;
                // bwin['J'] ++;
                bj ++;
                break;
        }
    }
    cout << a[0] << ' ' << a[1] << ' ' << a[2] << '\n';
    cout << a[2] << ' ' << a[1] << ' ' << a[0] << '\n';
    if(ab >= ac && ab >= aj)
        cout << "B ";
    else if(ac > ab && ac > aj)
        cout << "C ";
    else if(aj > ab && aj >= ac)
        cout << "J ";
    if(bb >= bc && bb >= bj)
        cout << 'B';
    else if(bc > bb && bc >= bj)
        cout << 'C';
    else if(bj > bb && bj > bc)
        cout << 'J';
    // int most = -1;
    // for(int i = 'B';i <= 'J';i ++) {
    //     cout << char(i) << ' ' << awin[i] << '\n';
    //     if(awin[i] > most)
    //         most = i;
    // }
    // cout << char(most) << ' ';
    // most = -1;
    // for(int i = 'B';i <= 'J';i ++) {
    //     if(bwin[i] > most)
    //         most = i;
    // }
    // cout << char(most);
}
