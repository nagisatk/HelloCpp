#include<iostream>
int test(int);
int main() {
    int num,max = 0;
    for(int i = 1;i < 101;i ++)
        if(test(i)>max)
            max = test(i);
    std::cout << max;
        // std::cout << i << " : " << test(i) << std::endl;
}

int test(int num) {
    if(num == 1)
        return 0;
    else if(num % 2 == 1)
        return test((3 * num + 1) / 2) + 1;
    else
        return test(num / 2) + 1;
}