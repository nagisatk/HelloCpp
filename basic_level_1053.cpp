/*****************************************************
 >    File Name: basic_level_1053.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/2/10 10:43:45
 *****************************************************/

#include<iostream>
#include<iomanip>
using namespace std;

int main() {
    double tol, may = 0, sure = 0, d, e, ek;
    cin >> tol >> e >> d;
    for(int i=0; i<tol; i++) {
        int k, t = 0;
        cin >> k;
        for(int j=0; j<k; j++) {
            cin >> ek;
            if(ek < e) t++;
        }
        if(k-t < t)
            if(k > d) sure++;
            else      may++;
        
    }
    cout << fixed << setprecision(1) << may*100/tol << "% " << sure*100/tol << "%\n";
}
