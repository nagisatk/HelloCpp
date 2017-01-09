#include<iostream>
using namespace std;

int main() {
    int top_coef, top_exp;
    cin >> top_coef >> top_exp;
    if(top_exp == 0) {
        cout << "0 0" << endl;
        return 0;
    }
    cout << top_coef * top_exp << ' '
         << top_exp - 1;
    int end = top_exp * 2;
    int coef_exp[end];
    for(int i = 0;i < end;i ++) {
        coef_exp[i] = 0;
        cin >> coef_exp[i];
        if(coef_exp[i] == '0')
            break;
    }
    for(int i = 0;i * 2 + 1 < end;i ++) {
        if(coef_exp[2 * i + 1] == 0 || coef_exp[2 * i] == 0)
            break;
        cout << ' ' << coef_exp[2 * i] * coef_exp[2 * i + 1]
             << ' ' << coef_exp[2 * i + 1] - 1;
    }
}