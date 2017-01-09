#include<iostream>
#define MAX 81
using namespace std;

int main() {
    char sentence[MAX];
    cin.getline(sentence, MAX);
    int end_index = 0;
    while(sentence[end_index])
        end_index ++;
    end_index --;
    for(int i = end_index; i > 0; i --) {
        if(sentence[i] == ' ') {
            for(int j = i + 1; j <= end_index; j ++) {
                cout << sentence[j];
            }
            cout << ' ';
            end_index = i - 1;
        }
    }
    int i = sentence[0] == ' ' ? 1 : 0;
    for(; i <= end_index; i ++)
        cout << sentence[i];
}