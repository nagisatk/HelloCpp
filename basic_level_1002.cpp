#include<iostream>
#include<stdio.h>
#include<memory.h>

#define MAX 101
#define NUM 3

using namespace std;

const char* cast_number(int a) {
    switch(a){
        case 0: return "ling";
        case 1: return "yi";
        case 2: return "er";
        case 3: return "san";
        case 4: return "si";
        case 5: return "wu";
        case 6: return "liu";
        case 7: return "qi";
        case 8: return "ba";
        case 9: return "jiu";
    }
    return "";
}

void print_pinyin(int sum) {
    int nums[NUM];
    int divisor = 10;
    for(int i = 0;i < NUM;i ++) {
        nums[i] = sum % divisor;
        sum /= divisor;
    }
    if(nums[2] != 0)
        for(int i = 2;i > 0;i --)
            cout << cast_number(nums[i]) << ' ';
    else if(nums[1] != 0)
        cout << cast_number(nums[1]) << ' ';
    cout << cast_number(nums[0]) << endl;
}

int get_sum() {
    char* numbers = new char[MAX];
    memset(numbers,'\0',MAX);
    cin.getline(numbers, MAX);
    int sum = 0;
    //error: lvalue required as increment operand
    while(*numbers) {
        sum += (*numbers++) - '0';
    }
    return sum;
}

int main() {
    int sum = get_sum();
    print_pinyin(sum);
    return 0;
}