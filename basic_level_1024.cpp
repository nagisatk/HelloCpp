/*****************************************************
 >    File Name: basic_level_1024.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/1/15 19:01:56
 *****************************************************/

#include<iostream>
using namespace std;

int get_index_of_e(char* in) {
    for(int i = 0;;i++)
        if(in[i] == 'E')
            return i;
}

void print_out(char* out, int index) {
    while(out[index])
           cout << out[index++];
}

void print_zero(int exp) {
    while(exp--)
        cout << 0;
}

int main() {
    char in[10001];
    char out[10001];
    cin >> in;
    int e = get_index_of_e(in);
    int valid = 0;
    for(int j = 0;j < e;j ++)
        if(in[j] != '.')
            out[valid++] = in[j];
    out[valid--] = 0;
    int exp = 0, index = e+2;
    while(in[index]) {
        exp = exp * 10 + in[index++] - '0';
    }
    index = 0;
    if(out[index] == '-')
        cout << out[index++];     // +/-
    else
        index++;
    if(exp == 0) {
        cout << out[index++] << '.';
        print_out(out, index);
        return 0;
    }
    if(in[e+1] == '+') {
        cout << out[index++];
        if(exp >= valid) {
            print_out(out, index);
            print_zero(exp - valid+1);
        }else{
            while(exp--)
                cout << out[index++];
            if(out[index]) {
                cout << '.';
                print_out(out, index);
            }
        }
    } else {
        cout << "0.";
        print_zero(--exp);
        print_out(out, index);
    }
}
