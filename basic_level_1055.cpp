/*****************************************************
 >    File Name: basic_level_1055.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outloocol.com
 > Created Time: 2017/2/10 20:30:16
 *****************************************************/

#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct per {
    char name[9];
    int tall;
};

bool compare(per* a, per* b) {
    if(a->tall != b->tall)
        return a->tall > b->tall;
    else
        return strcmp(a->name, b->name) < 0;
}

int main() {
    int n, col;
    cin >> n >> col;
    per *all[n];
    for(int i=0; i<n; i++) {
        all[i] = new per();
        cin >> all[i]->name >> all[i]->tall;
    }
    sort(all, all+n, compare);
    int row = n/col, last = n-row*(col-1);
    int sub = 0, index = last/2;
    per *bak[n];
    for(int step=0; step<last; step++) {
        if(step%2) index -= step;
        else       index += step;
        bak[index] = all[sub++];
    }
    index = last + row/2;
    for(int i=1; i<col; i++) {
        for(int step=0; step<row; step++) {
            if(step%2) index -= step;
            else       index += step;
            bak[index] = all[sub++];
        }
        index = last + row*i + row/2;
    }
    for(int i=0; i<last; i++)
        if(i) cout << ' ' << bak[i]->name;
        else  cout << bak[i]->name;
    cout << '\n';
    for(int i=0; i<col-1; i++) {
        for(int j=0; j<row; j++)
            if(j) cout << ' ' << bak[last+i*row+j]->name;
            else  cout << bak[last+i*row+j]->name;
        cout << '\n';
    }
}
