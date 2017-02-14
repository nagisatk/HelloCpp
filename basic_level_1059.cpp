/*****************************************************
 >    File Name: basic_level_1059.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/2/14 17:56:22
 *****************************************************/

#include<iostream>
#include<cmath>
using namespace std;

bool is_prime(int n) {
    double max = sqrt(n);
    for(int i = 2; i <= max; i ++)
        if(n % i == 0)
            return false;
    return true;
}

void print_id(int id) {
    if(id < 10)
        cout << "000";
    else if(id < 100)
        cout << "00";
    else if(id < 1000)
        cout << '0';
    cout << id << ": ";
}

void print_rank(int rank) {
    if(rank == 1)
        cout << "Mystery Award\n";
    else if(is_prime(rank))
        cout << "Minion\n";
    else
        cout << "Chocolate\n";
}

int main() {
    int n, k, id;
    cin >> n;
    int mems[10000] = {};
    for(int i=1; i<=n; i++) {
        cin >> id;
        mems[id] = i;
    }
    cin >> k;
    for(int i=0; i<k; i++) {
        cin >> id;
        print_id(id);
        if(mems[id] == 0)
            cout << "Are you kidding?\n";
        else if(mems[id] == 20000)
            cout << "Checked\n";
        else {
            print_rank(mems[id]);
            mems[id] = 20000;
        }
    }
}
