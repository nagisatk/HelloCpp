/*****************************************************
 >    File Name: basic_level_1044.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/2/7 15:01:14
 *****************************************************/

#include<iostream>
#include<string>
#define is_digit(c) (c)>='0' && (c)<='9'
using namespace std;

static string ones[13]= {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
static string tens[13]= {"tam",  "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

void print_earth_number(string& s) {
    int num = 0;
    for(int k = 0; k < s.size(); k += 4) {
        string temp = s.substr(k, 3);
        for(int j = 0; j < 13; j ++)
            if(temp == tens[j])
                num += (j+1)*13;
            else if(temp == ones[j])
                num += j;
    }
    cout << num << '\n';
}

void print_mars_number(int t) {
    if(t < 13)
        cout << ones[t%13] << '\n';
    else if(t >= 13 && t%13 == 0)
        cout << tens[t/13-1] << '\n';
    else if(t > 13)
        cout << tens[t/13-1] << ' ' << ones[t%13] << '\n';
}


int main() {int n = 0;
    cin >> n;
    string in[n];
    cin.get();
    for(int i = 0; i < n; i++) {
        getline(cin, in[i]);
    }
    for(int i = 0; i < n; i ++) {
        if(is_digit(in[i][0])) {
            int t = 0, j = 0;
            while(in[i][j])
                t = t*10 + in[i][j++] - '0';
            print_mars_number(t);
        } else {
            print_earth_number(in[i]);
        }
    }
}
