#include<iostream>
using namespace std;

bool is_upper(char c, char end) {
    return c >= 'A' && c <= end;
}

bool is_lower(char c) {
    return c >= 'a' && c <= 'z';
}

bool is_alpha(char c) {
    return is_upper(c, 'Z') || is_lower(c);
}

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

int get_day(char* str1, char* str2, int* index) {
    while(str1[*index] && str2[*index]) {
        if(str1[*index] == str2[*index])
            if(is_upper(str1[*index], 'G'))
                return str1[*index] - 'A';
        (*index) ++;
    }
}

int get_hour(char* str1, char* str2, int* index) {
    while(str1[*index] && str2[*index]) {
        if(str1[*index] == str2[*index]) {
            if(is_upper(str1[*index], 'N')) {
                return str1[*index] - 'A' + 10;
            } else if(is_digit(str1[*index])) {
                return str1[*index] - '0';
            }
        }
        (*index) ++;
    }
}

int get_minute(char* str3, char* str4) {
    int index = 0;
    while(str3[index] && str4[index]) {
        if(str3[index] == str4[index] && is_alpha(str3[index]))
            return index;
        index ++;
    }
}

int main() {
    char input[4][61];
    for(int i = 0; i < 4; i ++) {
        cin >> input[i];
    }
    int index = 0;
    int day = get_day(input[0], input[1], &index);
    index ++;
    int hour = get_hour(input[0], input[1], &index);
    int minute = get_minute(input[2], input[3]);
    switch(day) {
        case 0:cout << "MON ";break;
        case 1:cout << "TUE ";break;
        case 2:cout << "WED ";break;
        case 3:cout << "THU ";break;
        case 4:cout << "FRI ";break;
        case 5:cout << "SAT ";break;
        case 6:cout << "SUN ";break;
    }
    cout << hour/10 << hour%10
         << ':'
         << minute/10 << minute%10;
}