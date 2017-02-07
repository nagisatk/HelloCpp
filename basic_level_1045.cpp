/*****************************************************
 >    File Name: basic_level_1045.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/2/7 18:52:52
 *****************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int nums[n], temp[n], res[n];
    for(int i = 0; i < n; i ++) {
        cin >> nums[i];
        temp[i] = nums[i];
    }
    int max = 0;
    sort(nums, nums+n);
    int count = 0;
    for(int i = 0; i < n; i ++) {
        if(temp[i] == nums[i] && temp[i] > max)
            res[count++] = temp[i];
        if(temp[i] > max)
            max = temp[i];
    }
    cout << count << '\n';
    for(int i = 0; i < count; i ++)
        if(i)
            cout << ' ' << res[i];
        else
            cout << res[i];
    cout << endl;
}
