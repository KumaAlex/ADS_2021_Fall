#include <iostream>

using namespace std;

struct node{
    int val;
    node * next;
    node * prev;
    node(int x){
        val = x;
        next = prev = NULL;
    }
};

struct de{
    node * head;
    node * tail;
    de(){
        head = tail = NULL;
    }

    void push_back(int x){
        node * item = new node(x);
        if (tail == NULL && head == NULL) {
            tail = item;
            head = item;
        }else{
            tail->next = item;
            item->prev = tail;
            tail = item;
        }
    }

    void pop_front() {
        head = head->next;
        head->prev = NULL;
    }

    int front() {
        return head->val;
    }
};

int main() {
    int a, b, count = 0;
    cin >> a >> b;
    de a1, b1;
    for (int i = 0; i < a; i++) {
        a1.push_back(i);
    }
    for (int i = 0; i < b; i++) {
        b1.push_back(i);
    }
    int p1 = a1.front(), p2 = b1.front();
    a1.push_back(a1.front());
    a1.pop_front();
    b1.push_back(b1.front());
    b1.pop_front();
    count++;
    while (!(a1.front() == p1 && b1.front() == p2)) {
        a1.push_back(a1.front());
        a1.pop_front();
        b1.push_back(b1.front());
        b1.pop_front();
        count++;
    }
    cout << count;
    return 0;
}