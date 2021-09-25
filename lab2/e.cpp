#include <iostream>
#include <fstream>

using namespace std;

struct node{
    string val;
    node * next;
    node * prev;
    node(string x) {
        val = x;
        prev = NULL;
        next = NULL;
    }
};

struct st{
    node * head;
    node * tail;
    st() {
        head = tail = NULL;
    }
    void plus(string x) {
        node * item = new node (x);
        if (head == NULL) {
            head = tail = item;
        } else if (head == tail) {
            tail = item;
            head->next = tail;
            tail->prev = head;
        } else {
            tail->next = item;
            item->prev = tail;
            tail = item;
        }
    }
    int minus(string x) {
        if (head == NULL) return 1;
        node * item = new node (x);
        node * cur = tail;
        while (1 == 1) {
            if (cur->val == item->val && cur != head && cur != tail) {
                node * rig = cur->next;
                node * lef = cur->prev;
                rig->next = lef;
                lef->prev = rig;
            } else if (cur->val == item->val && cur == head && cur != tail) {
                head = head->next;
                head->prev = NULL;
            } else if (cur->val == item->val && cur != head && cur == tail) {
                tail = tail->prev;
                tail->next = NULL;
            } else if (cur->val == item->val && cur == head && cur == tail) {
                if (cur->val == item->val) {
                    head = tail = NULL;
                    return 0;
                } else {
                    return 1;
                }
            }
            cur = cur->prev;
            if (cur == NULL) return 0;
        }
        return 2;
    }
    void out(ostream& fout) {
        if (head == NULL) {
            fout << "EMPTY";
            return;
        }
        node * cur = head;
        while (cur != NULL) {
            fout << cur->val << " ";
            cur = cur->next;
        }
    }
};

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n;
    string s;
    st q;
    while(getline(fin, s)) {
        n = 0;
        if (s[0] == '+') {
            s.erase(0, 1);
            q.plus(s);
        } else if (s[0] == '-') {
            s.erase(0, 1);
            if (q.minus(s) == 1) {
                fout << "ERROR";
                return 0;
            }
        }
    }
    q.out(fout);
    fin.close();
    fout.close();
    return 0;
}