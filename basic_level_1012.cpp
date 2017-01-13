#include<iostream>
#include<iomanip>
using namespace std;

int main() {
    int A[5] = {0,0,0,0,0};
    double A4 = 0;
    int A2 = 0, times, flag = 1;
    cin >> times;
    for(int i = 0;i < times; i ++) {
        int input, remainder;
        cin >> input;
        remainder = input % 5;
        switch(remainder) {
            case 0 :
                if(input % 2 == 0)
                    A[0] += input;
                break;
            case 1 :
                A2 += flag * input;
                A[1] ++;
                flag = 0 - flag;
                break;
            case 2 :
                A[2] ++;
                break;
            case 3 :
                A4 += input;
                A[3] ++;
                break;
            case 4 :
                if(A[4] < input)
                    A[4] = input;
        }
    }
    if(A[0] == 0)
        cout << 'N';
    else
        cout << A[0];
    for(int i = 1;i < 5;i ++)
        if(A[i] == 0)
            cout << " N";
        else {
            cout << ' ';
            if(i == 1)
                cout << A2;
            else if(i == 3) {
                cout << std::fixed << setprecision(1) << (A4 / A[i]);
            } else
                cout << A[i];
        }
}