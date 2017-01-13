#include<iostream>
#include<cmath>
using namespace std;

bool is_prime(int n) {
    double max = sqrt(n);
    for(int i = 2; i <= max; i ++)
        if(n % i == 0)
            return false;
    return true;
}

void count_prime(int start, int end, int* result) {
    for(int i = 0, n = 2;i <= end; n ++)
        if(is_prime(n) && ++i >= start)
            *result++ = n;
}

int main() {
    int start, end, count;
    cin >> start >> end;
    int result[end - start + 1];
    count_prime(start, end, result);
    for(int i = 0;i < end - start + 1;i ++) {
        if(i % 10 == 0)
            cout << result[i];
        else if(i % 10 == 9)
            cout << ' ' << result[i] << endl;
        else
            cout << ' ' << result[i];
    }
}