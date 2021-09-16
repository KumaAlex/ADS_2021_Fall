#include <iostream>
using namespace std;

struct node {
    int val;
    node * next;
    node * prev;
    node (int x) {
        val = x;
        next = prev = NULL;
    }
};

struct st {
    node * tail;
    node * head;
    node * aver;
    bool OK, UP;
    st() {
        tail = head = aver = NULL;
        OK = true;
        UP = false;
    }
    void add(int x) {
        node * item = new node(x);
        if(tail == NULL && head == NULL) {
            head = tail = aver = item;
        }else{
            tail->next = item;
            item->prev = tail;
            tail = item;
        }
        if (OK) {
            OK = false;
            UP = false;
        } else if (!UP) UP = true;
        else {
            UP = false;
            aver = aver->next;
        }
    }
    void leave() {
        cout << head->val << endl;
        head = head->next;
        if (OK) {
            OK = false;
            UP = false;
        } else if (!UP) UP = true;
        else {
            UP = false;
            aver = aver->next;
        }
    }
    void supergob(int x) {
        node * item = new node(x);
        item->next = aver->next;
        aver->next = item;
        item->prev = aver;
        if (OK) {
            OK = false;
            UP = false;
        } else if (!UP) UP = true;
        else {
            UP = false;
            aver = aver->next;
        }
    }
};


int main() {
    int n;
    cin >> n;
    st q;
    for (int i = 0; i < n; i++) {
        char c;
        int a;
        cin >> c;
        if (c == '-') {
            q.leave();
        }
        if (c == '+') {
            cin >> a;
            q.add(a);
        }
        if (c == '*') {
            cin >> a;
            q.supergob(a);
        }
    }
    return 0;
}