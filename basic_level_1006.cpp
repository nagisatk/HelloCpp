#include<iostream>
using namespace std;

void print_formated_number(int n) {
    int individual = n % 10;
    int decade = n % 100 / 10;
    int hundred = n / 100;
    for(int i = 0;i < hundred;i++)
        cout << "B";
    for(int i = 0; i < decade;i++)
        cout << "S";
    for(int i = 1;i <= individual;i++)
        cout << i;
}

int main() {
    int num;
    cin >> num;
    print_formated_number(num);
}