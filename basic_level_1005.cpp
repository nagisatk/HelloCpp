#include<iostream>
using namespace std;

int next_number(int x) {
    if(x % 2 == 1)
        return (3 * x + 1) / 2;
    else
        return x / 2;
}

int main() {
    int times;
    cin >> times;
    int numbers[times];
    for(int i = 0; i < times; i++) {
        cin >> numbers[i];
    }

    for(int i = 0; i < times; i ++ ) {
        if(numbers[i] == 0)
            continue;
        int j = 0;
        int temp = numbers[i];
        while(j < times) {
            temp = next_number(temp);
            if(numbers[j] == 0 || temp == 1) {
                j ++;
                temp = numbers[i];
            } else if(numbers[j] == temp) {
                numbers[j] = 0;
                j ++;
                temp = numbers[i];
            }
        }
    }
    bool result[101];
    for(int i = 0; i < 100; i ++) {
        result[i] = false;
    }
    for(int i = 0; i < times; i++ ) {
        if(numbers[i])
            result[numbers[i]] = true;
    }
    int k = 100;
    for(; k > 1; k --) {
        if(result[k]) {
            cout << k;
            break;
        }
    }
    for(k--; k > 1; k --) {
        if(result[k]) {
            cout << " " << k;
        }
    }
}