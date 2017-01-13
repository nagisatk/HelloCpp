#include<iostream>
using namespace std;

void quicksort(int* a, int start, int end) {
    if(start >= end)
        return;
    int t = a[start];
    int low = start;
    int high = end;
    while(low < high) {
        while(low < high && a[high] > t)
            high --;
        if(low < high)
            a[low++] = a[high];
        while(low < high && a[low] < t)
            low ++;
        if(low < high)
            a[high--] = a[low];
        
    }
    a[high] = t;
    quicksort(a, start, low - 1);
    quicksort(a, low + 1, end);
}

void print_array(int* a) {
    for(int i = 0;i < 11;i ++)
        cout << a[i] << ' ';
    cout << endl;
}

int main() {
    int a[11] = {1,45,213,34,5424,423,535,145,523,5,325};
    print_array(a);
    quicksort(a, 0, 10);
    print_array(a);
}