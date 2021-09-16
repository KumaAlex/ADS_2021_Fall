#include <iostream>

using namespace std;

struct node{
    int val;
    node * next;
    node * prev;
    node (int x) {
        val = x;
        next = NULL;
        prev = NULL;
    }
};

struct st{
    node * head;
    node * tail;

    st(){
        tail = NULL;
        head = NULL;
    }

    int top() {
        if(tail != NULL) {
            return tail->val;
        }
        return -1;
    }

    int back() {
        if (head != NULL) {
            return head->val;
        }
    }

    void push(int x) {
        node * item = new node(x);
        if(tail == NULL) {
            tail = item;
        }else{
            tail->next = item;
            item->prev = tail;
            tail = item;
        }
    }

    void pop() {
        if(tail != NULL) {
            tail = tail->prev;
            if(tail != NULL){
                tail->next = NULL;
            }
        }
    }
};

int main() {
    int a[] = {1, 2, 3, 4, 5};
    st s;
    for (int i = 0; i < 5; i++) {
        s.push(a[i]);
    }
    for (int i = 0; i < 5; i++) {
        cout << s.top() << endl; 
        s.pop();
    }
    return 0;
}