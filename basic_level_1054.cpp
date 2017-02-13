/*****************************************************
 >    File Name: basic_level_1054.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/2/10 16:42:18
 *****************************************************/

#include<iostream>
#include<iomanip>
#include<cstring>
#define is_digital(c) ((c)>='0'&&(c)<='9')
using namespace std;

bool is_legal(char* s) {
    double d = atof(s);
    if(d > 1000.0 || d < -1000) return false;
    int i=0;
    if(s[i] == '-') i++;
    if(!is_digital(s[i])) return false;
    int point = 0, right = 0;
    for(; i<strlen(s); i++) {
        if(!is_digital(s[i]) && s[i] != '.') return false;
        if(point == 1)  right++;
        if(right > 2)   return false;
        if(s[i] == '.') point++;
        if(point > 1)   return false;
    }
    return true;
}

int main() {
    int n, count = 0;
    double sum = 0.0;
    cin >> n;
    char in[17] = {};
    for(int i=0; i<n; i++) {
        cin >> in;
        if(is_legal(in)) {
            double t = atof(in);
            sum += t;
            count++;
        } else
            cout << "ERROR: " << in << " is not a legal number\n";
    }
    switch(count) {
        case 0 :  cout << "The average of 0 numbers is Undefined\n";break;
        case 1 :  cout << "The average of 1 number is "
                       << fixed << setprecision(2) << sum << '\n';break;
        default : cout << "The average of " << count << " numbers is "
                       << fixed << setprecision(2) << sum/count << '\n';
    }
}