/*****************************************************
 >    File Name: basic_level_1047.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/2/8 14:02:27
 *****************************************************/

#include<iostream>
using namespace std;

int main() {
    int n, team, member, grade, teams[1001] = {}, winteam = 0, maxgrade = 0;
    char ch;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> team >> ch >> member >> grade;
        teams[team] += grade;
    }
    for(int i=0; i<1001; i++) {
        if(teams[i])
            if(teams[i] > maxgrade) {
                maxgrade = teams[i];
                winteam = i;
            }
    }
    cout << winteam << ' ' << maxgrade;
}
