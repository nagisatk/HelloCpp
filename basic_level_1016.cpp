#include<iostream>
using namespace std;

int get_sum(char* numbers, int key) {
    int sum = 0;
    while(*numbers) {
        if(*numbers - '0' == key)
            sum = sum * 10 + key;
        numbers++;
    }
    return sum;
}

int main() {
    int sum[2];
    for(int i = 0;i < 2;i ++) {
        char numbers[11];
        int key;
        cin >> numbers >> key;
        sum[i]   = get_sum(numbers, key);
    }
    cout << sum[0] + sum[1];
}
