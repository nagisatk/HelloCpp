/*****************************************************
 >    File Name: basic_level_1061.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/2/14 19:22:10
 *****************************************************/

#include<iostream>
using namespace std;

int main() {
    int s, q, a;
    cin >> s >> q;
    int scores[q], ans[q], grades[s] = {};
    for(int i=0; i<q; i++)
        cin >> scores[i];
    for(int i=0; i<q; i++)
        cin >> ans[i];
    for(int i=0; i<s; i++) {
        for(int j=0; j<q; j++) {
            cin >> a;
            grades[i] += (!(a^ans[j]))*scores[j];
        }
    }
    for(int i=0; i<s; i++)
        cout << grades[i] << '\n';
}
