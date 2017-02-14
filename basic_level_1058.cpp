/*****************************************************
 >    File Name: basic_level_1058.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/2/13 18:30:13
 *****************************************************/

#include<iostream>
using namespace std;

struct que {
    int score;
    int sels;
    int rights;
    int wrong;
    bool ans[5];
    inline que() {
        for(int i=0; i<5; i++)
            this->ans[i] = false;
        this->wrong = 0;
    }
};

int main() {
    int s, q;
    char c;
    cin >> s >> q;
    que *ques[q];
    for(int i=0; i<q; i++) {
        ques[i] = new que();
        cin >> ques[i]->score >> ques[i]->sels >> ques[i]->rights;
        for(int j=0; j<ques[i]->rights; j++) {
            cin >> c;
            ques[i]->ans[c-'a'] = true;
        }
    }
    int grades[s] = {};
    cin.get();
    for(int i=0; i<s; i++) {
        int index = 0;
        while((c=cin.get()) != '\n') {
            if(c == '(') {
                int tol;
                char select;
                bool right = true;
                cin >> tol;
                if(tol != ques[index]->rights)
                    right = false;
                for(int j=0; j<tol; j++) {
                    cin >> select;
                    if(right)
                        if(!ques[index]->ans[select-'a'])
                            right = false;
                }
                if(right)
                    grades[i] += ques[index]->score;
                else
                    ques[index]->wrong++;
                index++;
            }
        }
    }
    for(int i=0; i<s; i++)
        cout << grades[i] << '\n';
    int max_wrong = 0;
    for(int i=0; i<q; i++)
        if(ques[i]->wrong > max_wrong)
            max_wrong = ques[i]->wrong;

    if(max_wrong == 0)
        cout << "Too simple";
    else {
        cout << max_wrong;
        for(int i=0; i<q; i++)
            if(ques[i]->wrong == max_wrong)
                cout << ' ' << i+1;
    }
}
