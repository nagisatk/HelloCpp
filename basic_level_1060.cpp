/*****************************************************
 >    File Name: basic_level_1060.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/2/14 18:54:02
 *****************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int e, eday;
    cin >> eday;
    int emile[eday] = {};
    for(int i=0; i<eday; i++) {
        cin >> emile[i];
    }
    sort(emile, emile+eday);
    e = eday;
    for(int i=0; i<eday; i++)
        if(e>=emile[i]) e--;
        else            break;
    cout << e;
}
