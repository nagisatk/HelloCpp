/*****************************************************
 >    File Name: basic_level_1026.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/1/16 14:20:10
 *****************************************************/

#include<iostream>
#include<iomanip>
using namespace std;

int main() {
    int start, over;
    cin >> start >> over;
    int interval = over - start;
    int seconds = interval / 100;
    if(interval % 100 >= 50)
        ++seconds;
    int time[3];
    for(int i = 0;i <3;i++) {
        time[i] = seconds % 60;
        seconds /= 60;
    }
    cout << setw(2) << setfill('0') << time[2];
    for(int i = 1;i >= 0;i--) {
        cout << ":" << setw(2) << setfill('0') << time[i];
    }
}
