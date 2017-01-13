#include<iostream>
#include<algorithm>
using namespace std;

struct student {
    int sno;
    int morality;
    int talent;
    int total;
    inline student(){
        sno      = 0;
        morality = 0;
        talent   = 0;
        total    = 0;
    }
    inline bool before(student& other) {
        if(this->talent > other.talent)
            return true;
        else if(this->talent == other.talent)
            if(this->morality > other.morality)
                return true;
            else if(this->morality == other.morality)
                return this->sno < other.sno;
        return false;
    }
};

bool compare(student a, student b) {
    if(a.total != b.total)
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
    if(s.talent >= l && s.morality > s.talent)
        return 2;
    return 3;
}

// void sort_students(student* stus, int start, int end) {
    // if(start >= end)
        // return;
    // int left = start;
    // int right = end;
    // student temp = stus[start];
    // while(left < right) {
        // while(left < right && !stus[right].before(temp))
            // right --;
        // if(left < right)
            // stus[left++] = stus[right];
        // while(left < right && stus[left].before(temp))
            // left ++;
        // if(left < right)
            // stus[right--] = stus[left];
    // }
    // stus[left] = temp;
    // sort_students(stus, start, left-1);
    // sort_students(stus, left+1, end);
// }

int main() {
    int n, l, h;
    cin >> n >> l >> h;
    student stus[4][n];
    int count[4] = {};
    for(int i = 0;i < n;i ++) {
        student st;
        cin >> st.sno >> st.morality >> st.talent;
        int rank = get_rank(st, h, l);
        st.total = st.morality + st.talent;
        if(rank < 4) {
            stus[rank][count[rank]] = st;
            count[rank]++;
        }
    }
    cout << count[0] + count[1] + count[2] + count[3] << endl;
    for(int i = 0;i < 4;i ++) {
        // sort_students(stus[i], 0, count[i] - 1);
        sort(stus[i], stus[i] + count[i], compare);
        for(int j = 0;j < count[i];j ++) {
            cout << stus[i][j].sno  << ' ' << stus[i][j].morality << ' ' << stus[i][j].talent << endl;
        }
    }
    cin >> n;
}
