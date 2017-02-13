/*****************************************************
 >    File Name: basic_level_1051.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/2/9 16:55:33
 *****************************************************/

#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

struct complex {
    double real;
    double visu;
    inline complex(){}
    inline complex multi(complex& c) {
        double tr = this->real, tv = this->visu;
        this->real = tr*c.real - tv*c.visu;
        this->visu = tr*c.visu + tv*c.real;
        return *this;
    }
    inline void exp() {
        cout << fixed;
        cout << setprecision(2);
        // if(this->real == 0 && this->visu == 0) {
            // cout << 0 << endl;
            // return;
        // }
        if(this->real < 0 && this->real >= -0.005)
            cout << "0.00";
        else
            cout << this->real;
        if(this->visu >= 0)
            cout << "+" << this->visu << "i";
        else if(this->visu < 0 && this->visu > -0.005)
            cout << "+0.00i";
        else if(this->visu < 0)
            cout << this->visu << "i";
        cout << endl;
    }
};
int main() {
    double r1, p1, r2, p2;
    cin >> r1 >> p1 >> r2 >> p2;
    complex c1, c2;
    c1.real = r1*cos(p1);
    c1.visu = r1*sin(p1);
    c2.real = r2*cos(p2);
    c2.visu = r2*sin(p2);
    c1.multi(c2).exp();
}
