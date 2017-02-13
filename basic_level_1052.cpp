/*****************************************************
 >    File Name: basic_level_1052.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/2/9 18:18:54
 *****************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
    vector<string> vec[3];
    string line;
    for(int i=0; i<3; i++) {
        getline(cin, line);
        int l, r = 0;
        while(line[r]) {
            if(line[r] == '[') {
                l = ++r;
                while(line[++r] && line[r] != ']');
                if(!line[r]) break;
                vec[i].push_back(line.substr(l, r-l));
            }
            r++;
        }
    }
    int n;
    cin >> n;
    int emo[n][5];
    for(int i=0; i<n; i++)
        for(int j=0; j<5; j++)
            cin >> emo[i][j];
    for(int i=0; i<n; i++) {
        if(emo[i][0]*emo[i][1]*emo[i][2]*emo[i][3]*emo[i][4] < 1 ||
           emo[i][0] > vec[0].size() ||
           emo[i][1] > vec[1].size() ||
           emo[i][2] > vec[2].size() ||
           emo[i][3] > vec[1].size() ||
           emo[i][4] > vec[0].size())
            cout << "Are you kidding me? @\\/@\n";
        else
            cout << vec[0][emo[i][0]-1] << '(' << vec[1][emo[i][1]-1]
                 << vec[2][emo[i][2]-1] << vec[1][emo[i][3]-1] << ')'
                 << vec[0][emo[i][4]-1] << '\n';
    }
}
