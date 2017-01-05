#include<iostream>
int test(int);
int main() {
    int num;
    std::cin >> num;
    std::cout << test(num) << std::endl;
}

int test(int num) {
    if(num == 1)
        return 0;
    else if(num % 2 == 1)
        return test((3 * num + 1) / 2) + 1;
    else
        return test(num / 2) + 1;
}