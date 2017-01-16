/*****************************************************
 >    File Name: basic_level_1025.cpp
 >  Author Name: Nagisa
 > Mail Address: nagisa_tk@outlook.com
 > Created Time: 2017/1/15 21:36:49
 *****************************************************/

#include<iostream>
#include<iomanip>
using namespace std;

struct Node {
    int address;
    int value;
    Node* next;
    inline Node() {
        this->next = NULL;
    }
};

// bool address_equal(char* a, char* b) {
//     if(b == NULL)
//         return false;
//     while(*a && *b)
//         if(*a++ != *b++)
//             return false;
//     return true;
// }

void print_node(Node* node) {
    if(node->next == NULL)
        return;
    node = node->next;
    while(node != NULL) {
        cout << setw(5) << setfill('0') << node->address;
        cout << ' ' << node->value << ' ';
        if(node->next != NULL)
            cout << setw(5) << setfill('0') << node->next->address << '\n';
        else
            cout << "-1\n";
        node = node->next;
    }
}

void scope_reverse(Node* head, int scope, int times) {
    if(head == NULL || scope == 0 || times == 0)
        return;
    Node *current, *temp;
    current = head->next;
    while(times--) {
        int s = scope;
        while(current->next != NULL && s--) {
            temp = current->next;
            current->next = temp->next;
            temp->next = head->next;
            head->next = temp;
        }
        // cout << head->next->address << '\n';
        head = current;
        current = head->next;
    }
}

int get_total(Node* head) {
    int total = 0;
    while(head->next != NULL) {
        total++;
        head = head->next;
    }
    return total;
}

int main() {
    int head_address, total, reverse;
    ios::sync_with_stdio(false);
    cin >> head_address >> total >> reverse;
    Node all[100000];
     int nextads[total];
    for(int i = 0;i < total;i++) {
        int add, nextad;
        cin >> add;
        all[add].address = add;
        cin >> all[add].value >> nextad;
        if(nextad == -1){
            all[add].next = NULL;
        }else
            all[add].next = &all[nextad];
    }
    if(head_address == -1) {
        cout << "-1\n";
        return 0;
    }
  //  for(int i = 0;i < total;i++)
  //      cout << all[i].address << ' ' << all[i].value << ' ' << nextads[i] << '\n';
    
    
    Node* head = new Node();
    head->next = &all[head_address];
    total = get_total(head);
    // cout << total << endl;
    // bool flag = true;
    // for(int i = 0;i < total;i++) {
    //     if(flag && head_address == all[i].address) {
    //         head->next = &all[i];
    //         flag = false;
    //     }
    //     for(int j = 0;j < total;j++) {
    //         if(nextads[j] > 0 && all[i].address == nextads[j]) {
    //             all[j].next = &all[i];
    //             nextads[j] = -2;
    //             cout << j << ' ' << i << '\n';
    //         }
    //     }
    // }
    // print_node(head);
    int scope = reverse - 1;
    int times = total > reverse ? total / reverse : 1;
    scope_reverse(head, scope, times);
    print_node(head);
}
