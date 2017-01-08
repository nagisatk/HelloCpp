#include<iostream>
#define MAX 101

using namespace std;

bool judge_pat(char* pat) {
    int left = 0;
    int midd = 0;
    int righ = 0;
    while(*pat == 'A') {
        pat++;
        left++;
    }
    if(*pat != 'P') return false;
    pat++;
    while(*pat == 'A') {
        midd++;
        pat++;
    }
    if(*pat != 'T') return false;
    pat++;
    while(*pat == 'A') {
        righ++;
        pat++;
    }
    if(*pat != '\0') return false;
    if(midd != 0 && midd * left == righ) return true;
    return false;
}

int main() {
    int num;
    cin >> num;
    char pat[MAX];
    bool result[num];
    for(int i = 0; i < num; i ++) {
        cin >> pat;
        if(judge_pat(pat))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}