/*****************************************************
 >    File Name: basic_level_1044.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/2/4 13:00:15
 *****************************************************/

#include<iostream>
#include<fstream>
#define is_digit(c) (c) >= '0' && (c) <= '9'
using namespace std;

void print_mars_number(int t) {
    if(t == 0) {
        cout << "tret\n";
        return;
    }
    switch(t/13) {
        case 1  : cout << "tam";break;
        case 2  : cout << "hel";break;
        case 3  : cout << "maa";break;
        case 4  : cout << "huh";break;
        case 5  : cout << "tou";break;
        case 6  : cout << "kes";break;
        case 7  : cout << "hei";break;
        case 8  : cout << "elo";break;
        case 9  : cout << "syy";break;
        case 10 : cout << "lok";break;
        case 11 : cout << "mer";break;
        case 12 : cout << "jou";break;
    }
    if(t > 13 && t%13)
        cout << ' ';
    switch(t%13) {
        case 1  : cout << "jan";break;
        case 2  : cout << "feb";break;
        case 3  : cout << "mar";break;
        case 4  : cout << "apr";break;
        case 5  : cout << "may";break;
        case 6  : cout << "jun";break;
        case 7  : cout << "jly";break;
        case 8  : cout << "aug";break;
        case 9  : cout << "sep";break;
        case 10 : cout << "oct";break;
        case 11 : cout << "nov";break;
        case 12 : cout << "dec";break;
    }
    cout << '\n';
}

int get_number(int n) {
    switch(n) {
        case 447 : return 0;    break; // tret
        case 313 : return 1;    break; // jan
        case 301 : return 2;    break; // feb
        case 320 : return 3;    break; // mar
        case 323 : return 4;    break; // apr
        case 327 : return 5;    break; // may
        case 333 : return 6;    break; // jun
        case 335 : return 7;    break; // jly
        case 317 : return 8;    break; // aug
        case 328 : return 9;    break; // sep
        case 326 : return 10;   break; // oct
        case 339 : return 11;   break; // nov
        case 300 : return 12;   break; // dec
        case 322 : return 13;   break; // tam
        // case 313 : return 26;   break; // hel
        case 303 : return 39;   break; // maa
        case 325 : return 52;   break; // huh
        case 344 : return 65;   break; // tou
        // case 323 : return 78;   break; // kes
        case 310 : return 91;   break; // hei
        // case 320 : return 104;  break; // elo
        case 357 : return 117;  break; // syy
        // case 326 : return 130;  break; // lok
        case 324 : return 143;  break; // mer
        case 334 : return 156;  break; // jou
    }
}

void print_earth_number(char *n) {
    if(n[3] == 't') {
        cout << "0\n";
        return;
    }
    int ret = 0;
    int a = n[0]+n[1]+n[2];
    switch(a) {
        case 313 : if(n[0] == 'h') ret += 26;  else ret += get_number(a);break;
        case 323 : if(n[0] == 'k') ret += 78;  else ret += get_number(a);break;
        case 320 : if(n[0] == 'e') ret += 104; else ret += get_number(a);break;
        case 326 : if(n[0] == 'l') ret += 130; else ret += get_number(a);break;
        default  : ret += get_number(a);break;
    }
    if(n[3] == ' ')
        ret += get_number(n[4]+n[5]+n[6]);
    cout << ret << '\n';
}

int main() {
    int n = 0;
    cin >> n;
    char in[n][8];
    int k = 0, l = 0;
    getchar();
    for(int i = 0; i < n; i++) {
        cin.getline(in[i], 8);
    }
    for(int i = 0; i < n; i ++) {
        if(is_digit(in[i][0])) {
            int t = 0, j = 0;
            while(in[i][j]) {
                t = t*10 + in[i][j++] - '0';
            }
            print_mars_number(t);
        } else {
            print_earth_number(in[i]);
        }
    }
}
