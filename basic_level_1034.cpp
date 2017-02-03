/*****************************************************
>    File Name: basic_level_1034.cpp
>  Author Name: Nagisa
> Mail Address: nagisa_tk@outlook.com
> Created Time: 2017/1/18 11:03:18
*****************************************************/

#include<iostream>
#include<cmath>
using namespace std;

long long max_common_divisor(long long a, long long b) {
    if (a % b == 0)
        return abs(b);
    return max_common_divisor(b, a % b);
}

struct fraq {
    // char sym;
    // long long long longe;
    long long memb;
    long long deno;
    inline fraq() {}
    // inline fraq(char* expr) {
    //     long long sym = 1, i = 0;
    //     if(expr[i] == '-') {
    //         sym = -1;
    //         i++;
    //     }
    //     cout << sym << endl;
    //     long long t1 = 0, t2 = 0;
    //     for(;expr[i] != '/';i ++) {
    //         t1 = t1*10 + expr[i] - '0';
    //         cout << "t1:" << t1 << endl;
    //     }
    //     for(++i;expr[i];i++) {
    //         t2 = t2 * 10 + expr[i] - '0';
    //         cout << "t2:" << t2 << endl;
    //     }
    //     fraq(t1 * sym, t2);
    // }
    inline fraq(long long t1, long long t2) {
        this->memb = t1;
        this->deno = t2;
        // cout << this->memb << '/' << this->deno;
        this->abbreviation();
        // cout << this->memb << '/' << this->deno;
    }
    inline void expression() {
        // cout << "---" << this->memb << ' ' << this->deno << "---";
        if(this->deno == 0) {
            cout << "Inf";
        } else if (this->memb == 0) {
            cout << 0;
        } else if (this->deno == 1) {
            if (this->memb > 0)
                cout << this->memb;
            else
                cout << '(' << this->memb << ')';
        } else {
            if (this->memb > 0)
                if (this->memb > this->deno)
                    this->complex_expression();
                else
                    this->simple_expression();
            else {
                cout << '(';
                if (-this->memb > this->deno)
                    this->complex_expression();
                else
                    this->simple_expression();
                cout << ')';
            }
        }
    }
    inline void simple_expression() {
        cout << this->memb << '/' << this->deno;
    }
    inline void complex_expression() {
        long long z = this->memb / this->deno;
        cout << z << ' ' << abs(this->memb - this->deno * z) << '/' << this->deno;
    }
    // inline fraq* add(fraq* other) {
        // cout << this->memb*other->deno + this->deno*other->memb << endl;
        // cout << this->deno*other->deno << endl;
        // return new fraq(this->memb*other->deno + this->deno*other->memb, this->deno*other->deno);
    // }
    // inline fraq* diff(fraq* other) {
        // return new fraq(this->memb*other->deno - this->deno*other->memb, this->deno*other->deno);
    // }
    // inline fraq* multi(fraq* other) {
        // return new fraq(this->memb*other->memb, this->deno*other->deno);
    // }
    // inline fraq* div(fraq* other) {
        // return new fraq(this->memb*other->deno, this->deno*other->memb);
    // }
    inline void abbreviation() {
        if(this->deno == 0)
            return;
        long long mmd = max_common_divisor(this->memb, this->deno);
        // cout << mmd << endl;
        this->memb /= mmd;
        this->deno /= mmd;
        if(this->deno < 0) {
            this->memb *= -1;
            this->deno *= -1;
        }
        // cout << "memb:" << this->memb << " deno:" << this->deno << endl;
    }
};

void get_fraq_from_expr(char* expr, fraq* f) {
    int sym = 1;
    int i = 0;
    if (expr[i] == '-') {
        sym = -1;
        i++;
    }
    // cout << sym << endl;
    long long t1 = 0, t2 = 0;
    for (; expr[i] != '/'; i++) {
        t1 = t1 * 10 + expr[i] - '0';
        // cout << "t1:" << t1 << endl;
    }
    for (++i; expr[i]; i++) {
        t2 = t2 * 10 + expr[i] - '0';
        // cout << "t2:" << t2 << endl;
    }
    *f = fraq(t1 * sym, t2);
}
void add(fraq* f1, fraq* f2, fraq* f3) {
    f3->memb = f1->memb*f2->deno + f1->deno*f2->memb;
    f3->deno = f1->deno*f2->deno;
    f3->abbreviation();
}
void diff(fraq* f1, fraq* f2, fraq* f3) {
    f3->memb = f1->memb*f2->deno - f1->deno*f2->memb;
    f3->deno = f1->deno*f2->deno;
    f3->abbreviation();
}
void multi(fraq* f1, fraq* f2, fraq* f3) {
    f3->memb = f1->memb*f2->memb;
    f3->deno = f1->deno*f2->deno;
    f3->abbreviation();
}
void div(fraq* f1, fraq* f2, fraq* f3) {
    f3->memb = f1->memb*f2->deno;
    f3->deno = f1->deno*f2->memb;
    f3->abbreviation();
}


int main() {
    char input1[30];
    char input2[30];
    cin >> input1 >> input2;
    fraq* f1 = new fraq();
    fraq* f2 = new fraq();
    get_fraq_from_expr(input1, f1);
    get_fraq_from_expr(input2, f2);
    // f1->expression();
    // cout << ' ';
    // f2->expression();
    // cout << endl;
    void (*cals[4])(fraq* f1, fraq* f2, fraq* f3) = {
        add,
        diff,
        multi,
        div
    };
    char opers[4] = {'+','-','*','/'};
    for(int i = 0;i < 4;i ++) {
        f1->expression();
        cout << ' ' << opers[i] << ' ';
        f2->expression();
        cout << " = ";
        fraq f3;
        cals[i](f1, f2, &f3);
        f3.expression();
        cout << '\n';
    }
    
    // prlong long_add_exprission(f1, f2);
    // prlong long_dif_exprission(f1, f2);
    // prlong long_mul_exprission(f1, f2);
    // prlong long_div_exprission(f1, f2);
    // fraq* add = f1->add(f2);
    // add->expression();
    // fraq f = fraq(13,2);
    // f.expression();
    // char expr[12];
    // cin >> expr;
    // fraq* f2 = new fraq();
    // get_fraq_from_expr(expr, f2);
    // // cout << "f2:" << f2->memb << endl;
    // f2->expression();
    // cout << ' ' << max_common_divisor(12, 3);
    // cout << ' ' << max_common_divisor(15, 30);
    // cout << ' ' << max_common_divisor(12, 30);
    // cout << ' ' << max_common_divisor(12, 2);
    // cout << ' ' << max_common_divisor(12, 31);
    // cout << ' ' << max_common_divisor(12, 1);
    // cout << ' ' << max_common_divisor(12, 3);
    // cout << ' ' << max_common_divisor(12, 3);
    // cout << ' ' << max_common_divisor(12, 3);
    // cout << ' ' << max_common_divisor(12, 3);
    // cin.get();
    // cin.get();
}
