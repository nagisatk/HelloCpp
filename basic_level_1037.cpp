/*****************************************************
 >    File Name: basic_level_1037.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/2/3 11:11:24
 *****************************************************/

#include<iostream>
using namespace std;

struct money {
    int gal;
    int sic;
    int knu;
    inline money() {
        this->gal = 0;
        this->sic = 0;
        this->knu = 0;
    }
    inline void exp() {
        cout << gal << '.' << sic << '.' << knu;
    }
    inline void diff(money* a) {
        if(this->greater_equal(a)) {
            this->gal -= a->gal;
            this->sic -= a->sic;
            this->knu -= a->knu;
            if(this->knu < 0) {
                this->sic--;
                this->knu += 29;
            }
            if(this->sic < 0) {
                this->gal--;
                this->sic += 17;
            }
        } else {
            this->gal = a->gal - this->gal;
            this->sic = a->sic - this->sic;
            this->knu = a->knu - this->knu;
            if(this->knu < 0) {
                this->sic--;
                this->knu += 29;
            }
            if(this->sic < 0) {
                this->gal--;
                this->sic += 17;
            }
            this->gal *= -1;
        }
    }
    inline bool greater_equal(money *a) {
        if(this->gal > a->gal)
            return true;
        else if(this->gal < a->gal)
            return false;
        else if(this->sic > a->sic)
            return true;
        else if(this->sic < a->sic)
            return false;
        else if(this->knu > a->knu)
            return true;
        else if(this->knu < a->knu)
            return false;
        else
            return true;
    }
};

int main() {
    char pay[15];
    char act[15];
    money *p = new money();
    money *a = new money();
    cin >> pay >> act;
    int i = 0;
    while(pay[i] != '.')
        p->gal = p->gal*10 + pay[i++] - '0';
    i++;
    while(pay[i] != '.')
        p->sic = p->sic*10 + pay[i++] - '0';
    i++;
    while(pay[i])
        p->knu = p->knu*10 + pay[i++] - '0';
    i = 0;
    while(act[i] != '.')
        a->gal = a->gal*10 + act[i++] - '0';
    i++;
    while(act[i] != '.')
        a->sic = a->sic*10 + act[i++] - '0';
    i++;
    while(act[i])
        a->knu = a->knu*10 + act[i++] - '0';
    a->diff(p);
    a->exp();
}
