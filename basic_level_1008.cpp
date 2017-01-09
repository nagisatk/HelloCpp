#include<iostream>
using namespace std;

int main() {
    int end, right;
    cin >> end >> right;
    int numbers[end];
    for(int i = 0;i < end; i ++) {
        cin >> numbers[i];
    }
    if(right % end == 0) {
        cout << numbers[0];
        for(int i = 1;i < end;i ++)
            cout << ' ' << numbers[i];
        return 0;
    }
    right = end - right % end;
    for(int i = right;i < end;i ++) {
        cout << numbers[i] << ' ';
    }
    cout << numbers[0];
    for(int i = 1;i < right;i ++) {
        cout << ' ' << numbers[i];
    }
}