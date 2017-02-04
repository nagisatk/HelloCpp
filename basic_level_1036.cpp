/*****************************************************
 >    File Name: basic_level_1036.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/2/3 10:36:19
 *****************************************************/

#include<iostream>
using namespace std;

int main() {
    int col, row;
    char c;
    cin >> col >> c;
    row = col/2 + col%2;
    for(int i = 0; i < col * row; i ++) {
        if(i%col == 0)
            cout << c;
        else if(i/col == 0 || i/col == row-1 || i%col == col-1)
            cout << c;
        else
            cout << ' ';
        if(i%col == col-1)
            cout << '\n';
    }
    // for(int i = 0;i < col;i++)
    //     cout << c;
    // cout << '\n';
    // for(int i = 1;i < row-1; i++) {
    //     cout << c;
    //     for(int j = 1;j < col - 1; j++)
    //         cout << ' ';
    //     cout << c << '\n';
    // }
    // for(int i = 0; i < col; i ++)
    //     cout << c;
}
