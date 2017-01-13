#include<iostream>

int step(int num) {
    if(num == 1)
        return 0;
    else if(num % 2 == 1)
        return step((3 * num + 1) / 2) + 1;
    else
        return step(num / 2) + 1;
}

int main() {
    int num,max = 0;
    for(int i = 1;i < 101;i ++)
        if(step(i)>max)
            max = step(i);
    std::cout << max;
}