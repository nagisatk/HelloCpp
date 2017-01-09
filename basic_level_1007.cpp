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

int count_prime_pair(int n) {
    if(n < 5)
        return 0;
    int odd;
    if(n % 2 == 1)
        odd = n / 2 + 1;
    else
        odd = n / 2;
    bool result[odd];
    result[0] = false;
    result[1] = true;
    for(int i = 2; i < odd; i ++)
        if(is_prime(i * 2 + 1))
            result[i] = true;
        else
            result[i] = false;
    int correct = 0;
    for(int i = 1; i < odd - 1; i ++)
        if(result[i] && result[i + 1])
            correct ++;
    return correct;
}

int main() {
    int num;
    cin >> num;
    cout << count_prime_pair(num) << endl;
}