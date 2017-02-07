/*****************************************************
 >    File Name: basic_level_1041.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/2/4 10:39:43
 *****************************************************/

#include<iostream>
using namespace std;

struct stu {
    long long sno;
    int mac;
    int test;
    inline stu() {
        this->sno  = 0;
        this->mac  = 0;
        this->test = 0;
    }
    inline void output() {
        cout << this->sno << ' ' << this->test << '\n';
    }
};

int main() {
    int n;
    cin >> n;
    stu *result[n];
    long long sno;
    int mac, test;
    for(int i = 0; i < n; i ++) {
        cin >> sno >> mac >> test;
        result[mac] = new stu();
        result[mac]->sno  = sno;
        result[mac]->mac  = mac;
        result[mac]->test = test;
    }
    int m;
    cin >> m;
    int search[m];
    for(int i = 0; i < m; i ++) {
        cin >> search[i];
    }
    for(int i = 0; i < m; i ++) {
        result[search[i]]->output();
    }
}
