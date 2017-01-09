#include<iostream>
using namespace std;

int next_number(int x) {
    if(x % 2 == 1)
        return (3 * x + 1) / 2;
    else
        return x / 2;
}

void get_all_numbers(int x, int* all) {
    x = next_number(x);
    while(x != 1) {
        *all ++ = x;
        x = next_number(x);
    }
}

bool find(int* all, int value) {
    while(*all) {
        if(*all++ == value)
            return true;
    }
    return false;
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
        else {
            int* temp = new int[75];
            get_all_numbers(numbers[i], temp);
            for(int j = 0; j < times; j ++) {
                if(find(temp, numbers[j]))
                    numbers[j] = 0;
            }
            delete temp;
        }

    }
    bool result[101];
    for(int i = 0; i < 101; i ++) {
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