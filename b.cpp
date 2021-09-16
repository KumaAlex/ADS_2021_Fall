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

    void push_front(int x){
        node * item = new node(x);
        if (tail == NULL && head == NULL) {
            head = item;
            tail = item;
        }else{
            head->prev = item;
            item->next = head;
            head = item;
        }
    }

    void pop_back() {
        if (tail != NULL) {
            tail = tail->prev;
            if (tail != NULL) {
                tail->next = NULL;
            }
        }
    }

    void pop_front() {
        if (head != NULL) {
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            }
        }
    }

    int front() {
        return head->val;
    }

    int back() {
        return tail->val;
    }
};

int main() {
    de d;
    int a[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++) {
        d.push_back(a[i]);
    }
    for (int i = 0; i < 3; i++) {
        cout << d.back() << endl;
        d.pop_back();
    }
    for (int i = 0; i < 3; i++) {
        cout << d.front() << endl;
        d.pop_front();
    }
    return 0;
}