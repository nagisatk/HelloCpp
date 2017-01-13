#include<iostream>
using namespace std;

int main() {
    int times;
    cin >> times;
    long long inputs[times * 3];
    for(int i = 0;i < times;i ++ )
        cin >> inputs[3 * i] >> inputs[3 * i + 1] >> inputs[3 * i + 2];
    for(int i = 0; i < times; i ++)
        if(inputs[3 * i] + inputs[3 * i + 1] > inputs[3 * i + 2])
            cout << "Case #" << i + 1 << ": true" << endl;
        else
            cout << "Case #" << i + 1 << ": false" << endl;
}