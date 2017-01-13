#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

struct student {
    int sno;
    int morality;
    int talent;
    int total;
    int rank;
};

bool compare(student a, student b) {
    if(a.rank != b.rank)
        return a.rank < b.rank;
    else if(a.total != b.total)
        return a.total > b.total;
    else if(a.morality != b.morality)
        return a.morality > b.morality;
    return a.sno < b.sno;
}

int get_rank(student& s, int h, int l) {
    if(s.morality >= h && s.talent >= h)
        return 0;
    if(s.morality < l || s.talent < l)
        return 4;
    if(s.morality >= h)
        return 1;
    if(s.talent >= l && s.morality >= s.talent)
        return 2;
    return 3;
}

int main() {
    int n, l, h;
    scanf("%d %d %d", &n, &l, &h);
    student stus[n];
    int c = 0;
    for(int i = 0;i < n;i ++) {
        student st;
        scanf("%d %d %d",&st.sno,&st.morality,&st.talent);
        // cin >> st.sno >> st.morality >> st.talent;
        st.rank = get_rank(st, h, l);
        st.total = st.morality + st.talent;
        if(st.rank < 4) {
            stus[c++] = st;
        }
    }
    cout << c << endl;
    sort(stus, stus+c, compare);
    for(int i = 0;i < c;i++)
        printf("%d %d %d\n", stus[i].sno, stus[i].morality, stus[i].talent);
        // cout << stus[i].sno  << ' ' << stus[i].morality << ' ' << stus[i].talent << endl;
    cin >> n;
}
