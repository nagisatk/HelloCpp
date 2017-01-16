/*****************************************************
 >    File Name: basic_level_1027.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/1/16 14:31:13
 *****************************************************/

#include<iostream>
#include<cmath>
using namespace std;

int cal_max_layer(int total) {
    if(total == 0)
        return 0;
    if(total < 7)
        return 1;
    int layer = 2;
    while(layer * layer * 2 - 1 < total)
        layer++;
    return --layer;
}

int main() {
    int total;
    char sym;
    cin >> total >> sym;
    int layer = cal_max_layer(total);
    int bot = layer * 2 - 1;
    int unused = total - (layer * layer * 2 - 1);
    for(int i = 0;i < bot;i++) {
        int sym_num = abs(i - bot/2) * 2 + 1;
        int blank = (bot - sym_num) / 2;
        while(blank--)
            cout << ' ';
        while(sym_num--)
            cout << sym;
        // int blank = bot/2 - abs(i - bot/2);
        // for(int j = 0;j < bot;j++) {
        //     if(j < blank || j > bot - blank - 1) {
        //         cout << ' ';
        //     }else{
        //         cout << sym;
        //     }
        // }
        cout << '\n';
    }
    cout << unused;
}
