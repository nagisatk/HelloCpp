/*****************************************************
 >    File Name: basic_level_1039.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/2/3 15:17:36
 *****************************************************/

#include<iostream>
using namespace std;

int main() {
    int store[128] = {};
    int red[128]   = {};
    char in1[1001], in2[1001];
    cin >> in1 >> in2;
    int i = 0;
    while(in1[i])
        store[in1[i++]]++;
    i = 0;
    while(in2[i])
        red[in2[i++]]++;
    bool res = true;
    for(i = 0; i < 128; i++) {
        if(store[i] < red[i]) {
            res = false;
            break;
        }
        i ++;
    }
    int count = 0;
    if(res) {
        for(i = 0; i < 128; i++) {
            if(red[i] > 0) {
                store[i] -= red[i];
            }
            count += store[i];
        }
        cout << "Yes " << count;
    } else {
        for(i = 0; i < 128; i ++) {
            if(red[i] > 0)
                red[i] = store[i] > red[i] ? 0 : red[i]-store[i];
            count += red[i];
        }
        cout << "No " << count;
    }
}
