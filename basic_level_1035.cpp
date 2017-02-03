/*****************************************************
 >    File Name: basic_level_1035.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/1/19 10:19:42
 *****************************************************/

#include<iostream>
using namespace std;

bool equal_seq(int *a, int *b, int num) {
    for(int i = 0; i < num; i ++)
        if(a[i] != b[i])
            return false;
    return true;
}

void print_seq(int *seq, int num) {
    cout << seq[0];
    for(int i = 1;i < num;i ++)
        cout << ' ' << seq[i];
    cout << '\n';
}

void insertion_sort(int *res, int i, int n) {
    int t = res[i + 1];
    while(i >= 0 && res[i] > t)
        res[i+1] = res[i--];
    res[i+1] = t;
}

void merge_array(int *a, int *b, int s, int e, int m) {
    int i = s, j = m + 1;
    int k = 0;
    while(i <= m && j <= e)
        if(a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    
    while(i <= m)
        b[k++] = a[i++];
    while(j <= e)
        b[k++] = a[j++];
    
    for(k--;k >= 0;k--)
        a[s + k] = b[k];
}

// void merge_array(int *a, int *b, int s, int e, int m) {
    // int i = s, j = m + 1;
    // int k = 0;
    // while(i <= m && j <= e) {
        // if(a[i] < a[j])
            // b[k++] = a[i++];
        // else
            // b[k++] = a[j++];
    // }
    
    // while(i <= m)
        // b[k++] = a[i++];
    // while(j <= e)
        // b[k++] = a[j++];
    
    // for(k--;k >= 0;k--)
        // a[s + k] = b[k];
// }

// void merge_sort(int *a, int *b, int s, int e, int num) {
    // if(s < e) {
        // int mid = (s + e) / 2;
        // merge_sort(a, b, s, mid, num);
        // merge_sort(a, b, mid + 1, e, num);
        // if(!equal_seq(a,b,num))
            // return;
        // merge_array(a, b, s, e, mid);
    // }
// }

// void call_merge_sort(int *a, int n) {
    // int b[n];
    // merge_sort(a, b, 0, n-1);
// }

void merge_sort(int *seq, int *temp, int n, int *bak) {
    for(int step = 1;step < n;step *= 2) {
        // int left = 0;
        // int right = 2*step > n ? n-1 : 2*step-1;
        // while(left < n-1) {
            // merge_array(seq, temp, left, right, left+step);
            // cout << "Step " << step << ": ";
            // print_seq(seq, n);
            // left += 2*step;
            // right = left + 2*step > n ? n-1:left+2*step-1;
        // }
        
        int s = 0;
        int end = 2*step > n-1 ? n-1 : 2*step-1;
        while(s < n-step) {
            merge_array(seq, temp, s, end, s+step-1);
            // cout << "Step " << step << "; ";
            // cout << "Left " << s << "; ";
            // cout << "Right " << end << ": ";
            // print_seq(seq, n);
            s += 2*step;
            end = s + 2*step > n-1 ? n-1 : s+2*step-1;
        }
        if(!equal_seq(seq, bak, n))
            return;
    }
}


int main() {
    int n;
    cin >> n;
    int seq[n], res[n];
    for(int i = 0;i < n;i ++)
        cin >> seq[i];
    for(int i = 0;i < n;i ++)
        cin >> res[i];
    int i, j;
    for (i = 0; i < n - 1 && res[i] <= res[i + 1]; i++);
    for (j = i + 1; seq[j] == res[j] && j < n; j++);
    if(j == n) {
        cout << "Insertion Sort\n";
        insertion_sort(res, i, n);
    } else {
        int t[n], bak[n];
        for(int i = 0;i < n;i ++)
            bak[i] = res[i];
        merge_sort(res, t, n, bak);
        cout << "Merge Sort\n";
    }
    print_seq(res, n);
}
