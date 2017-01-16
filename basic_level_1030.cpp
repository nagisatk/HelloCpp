/*****************************************************
 >    File Name: basic_level_1030.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/1/16 18:14:23
 *****************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int num;
    long long para;
    ios::sync_with_stdio(false);
    cin >> num >> para;
    long long seq[num] = {};
    for(int i = 0;i < num;i ++)
        cin >> seq[i];
    sort(seq, seq + num);
    int most = 1;
    for(int i = 0;i < num - most;i++) {
        for(int j = i + most - 1;j < num;j ++) {
            if(seq[i] * para >= seq[j]) {
                if(j - i + 1 > most)
                    most = j - i + 1;
            } else {
                break;
            }
        }
    }
    cout << most;
}
