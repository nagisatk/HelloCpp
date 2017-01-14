/*****************************************************
 >    File Name: basic_level_1020.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/1/14 18:15:26
 *****************************************************/

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

struct mooncake {
    float stock;
    float total;
};

bool compare(mooncake a, mooncake b) {
    return a.total/a.stock > b.total/b.stock;
}

int main() {
    int kind, need;
    cin >> kind >> need;
    mooncake cakes[kind];
    for(int i = 0;i < kind;i ++)
        cin >> cakes[i].stock;
    for(int i = 0;i < kind;i ++)
        cin >> cakes[i].total;
    sort(cakes, cakes + kind, compare);
    float total = 0;
    int i = 0;
    while(need > cakes[i].stock && i < kind) {
        need -= cakes[i].stock;
        total += cakes[i++].total;
    }
    if(i < kind) {
        float diff = float(need) / cakes[i].stock * cakes[i].total;
        total += diff;
    }
    cout << std::fixed << setprecision(2) << total;
}
