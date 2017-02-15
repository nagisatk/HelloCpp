/*****************************************************
 >    File Name: basic_level_1065.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/2/15 9:50:51
 *****************************************************/

#include<iostream>
using namespace std;

void print_id(int id, bool blank) {
    if(blank) cout << ' ';
    if(id < 10)
        cout << "0000";
    else if(id < 100)
        cout << "000";
    else if(id < 1000)
        cout << "00";
    else if(id < 10000)
        cout << '0';
    cout << id;
}

int main() {
    int n, m, t, single, party[100000] = {};
    cin >> n;
    int cps[n][2];
    for(int i=0; i<n; i++)
        cin >> cps[i][0] >> cps[i][1];
    cin >> m;
    single = m;
    while(m--) {
        cin >> t;
        party[t] = 1;
    }
    for(int i=0; i<n; i++)
        if(party[cps[i][0]] && party[cps[i][1]]) {
            party[cps[i][0]] = 0;
            party[cps[i][1]] = 0;
            single -= 2;
        }
    cout << single << '\n';
    if(single == 0)
        return 0;
    single = -1;
    while(!party[++single]);
    print_id(single, false);
    for(single++; single<100000; single++)
        if(party[single])
            print_id(single, true);
}
