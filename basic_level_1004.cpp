#include<iostream>
using namespace std;

void assign_content(char* old_chars, char* new_chars) {
    while(*new_chars)
        *old_chars++ = *new_chars++;
    *old_chars = '\0';
}

int main() {
    int times;
    cin >> times;
    char top_name[11],bot_name[11],top_sno[11],bot_sno[11];
    int top_mark = 0,bot_mark = 100;
    for (int i = 0; i < times; i ++ ) {
        char name[11],sno[11];
        int mark;
        cin >> name >> sno >> mark;
        if(mark > top_mark) {
            top_mark = mark;
            assign_content(top_name, name);
            assign_content(top_sno, sno);
        }
        if(mark < bot_mark) {
            bot_mark = mark;
            assign_content(bot_name, name);
            assign_content(bot_sno, sno);
        }
    }
    cout << top_name << " " << top_sno << "\n";
    cout << bot_name << " " << bot_sno << "\n";
}