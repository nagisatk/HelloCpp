/*****************************************************
>    File Name: basic_level_1028.cpp
>  Author Name: Nagisa
> Mail Address: nagisa_tk@outlook.com
> Created Time: 2017/1/16 15:46:31
*****************************************************/

#include<iostream>
#include<cstring>
using namespace std;

struct person {
    char name[6];
    int year;
    int mon;
    int day;
    inline person() {}
    inline person(int year, int mon, int day) {
        this->year = year;
        this->mon = mon;
        this->day = day;
    }
    inline void record(person* p) {
        strcpy(this->name, p->name);
        this->year = p->year;
        this->mon = p->mon;
        this->day = p->day;
    }
    inline void show() {
        cout << ' ' << this->name; //<< ' ' << this->year << '/' << this->mon << '/' << this->day << '\n';
    }
};

bool compare(person* a, person* b) {
    if (a->year != b->year)
        return a->year < b->year;
    else if (a->mon != b->mon)
        return a->mon < b->mon;
    else
        return a->day < b->day;
}

int cal_time(char* info, int start, int end) {
    int t = 0;
    while (start < end)
        t = t * 10 + info[start++] - '0';
    return t;
}

void record_person(person* per, char* info) {
    per->year = cal_time(info, 0, 4);
    per->mon = cal_time(info, 5, 7);
    per->day = cal_time(info, 8, 10);
    // cout << "year:" << per->year << endl;
    // cout << " mon:" << per->mon  << endl;
    // cout << " day:" << per->day  << endl;
}

int main() {
    int total;
    cin >> total;
    person pers[total];
    int valid = 0;
    person* longest = new person(1814, 9, 5);
    person* sho = new person(1814, 9, 5);
    person* shortest = new person(2014, 9, 7);
    person* lon = new person(2014, 9, 7);
    while (total--) {
        person* p = new person();
        cin >> p->name;
        char info[11];
        cin >> info;
        record_person(p, info);
        if (compare(longest, p) && compare(p, shortest)) {
            if(compare(p, lon)) {
                lon->record(p);
            }
            if(compare(sho, p))
                sho->record(p);
            valid++;
        }
    }
    cout << valid;
    if(valid > 0) {
        lon->show();
        sho->show();
    }
    // for(int i = 0;i < valid;i++)
    //     pers[i].show();
    
}
