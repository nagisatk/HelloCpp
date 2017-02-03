/*****************************************************
 >    File Name: basic_level_1031.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/1/16 20:50:14
 *****************************************************/

#include<iostream>
#include<cstring>
using namespace std;

bool is_all_number(char* id) {
    for(int i = 0;i < 17;i ++) {
        if(id[i] > '9' || id[i] < '0')
            return false;
    }
    return true;
}

char weighted_mod(char* id) {
    static int weis[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    static char mod[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    int sum = 0;
    for(int i = 0;i < 17;i ++)
        sum += (id[i] - '0') * weis[i];
    return mod[sum % 11];
}

int main() {
    int n;
    cin >> n;
    char ids[n][19];
    char bads[n][19];
    int bad = 0;
    for(int i = 0;i < n;i++)
        cin >> ids[i];
    
    for(int i = 0;i < n;i++) {
        if(is_all_number(ids[i])) {
            if(weighted_mod(ids[i]) != ids[i][17])
                strcpy(bads[bad++], ids[i]);
        } else {
            strcpy(bads[bad++], ids[i]);
        }
    }

    if(bad == 0)
        cout << "All passed";
    else
        for(int i = 0;i < bad;i++)
            cout << bads[i] << '\n';

}
