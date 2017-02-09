/*****************************************************
 >    File Name: basic_level_1050.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/2/8 19:15:08
 *****************************************************/

#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

void print(int *nums, int *mat, int m, int n) {
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(j)
                cout << ' ' << nums[mat[i*n+j]];
            else
                cout << nums[mat[i*n+j]];
        }
        cout << '\n';
    }
}

int main() {
    int tol, m, n;
    cin >> tol;
    int nums[tol];
    for(int i=0; i<tol; i++) {
        cin >> nums[i];
    }
    double t = sqrt(tol);
    m = t > int(t) ? t+1 : t;
    while(tol%m) m++;
    n = tol/m;
    // cout << m << endl;
    sort(nums, nums+tol);
    int mat[m*n] = {};
    int max = m*n-1, dif = 0;
    int up, down;
    for(int i=0; i<m/2; i++) {
        up = max - dif;
        dif += (m+n-2)*2-(i*8);
        down = max-dif + (m - 2*i - 1);
        for(int j=i; j<n-i; j++) {
            mat[i*n+j] = up--;
            mat[(m-1-i)*n+j]=down++;
        }
        // cout << max << ' ' << "\t\t" << dif << '\n';
    }
    // max=m*n;
    dif=0;
    int left, right;
    int mid = n%2 ? n/2+1 : n/2;
    for(int i=0; i<mid; i++) {
        right = max - (dif+(n-i*2));
        dif += (m+n-2)*2-(i*8);
        left = max-dif;
        for(int j=i+1; j<m-i-1; j++) {
            mat[j*n+i] = ++left;
            mat[n*(j+1)-i-1]=right--;
        }
    }
    print(nums, mat, m, n);
}
