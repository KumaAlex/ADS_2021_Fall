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
    string minus(string x) {
        if (head == NULL) return "ERROR";
        node * cur = tail;
        while (cur != NULL) {
            if (cur->val == x && cur != head && cur != tail) {
                node * rig = cur->next;
                node * lef = cur->prev;
                rig->prev = lef;
                lef->next = rig;
                return "OK";
            } else if (cur->val == x && cur == head && cur != tail) {
                head = head->next;
                head->prev = NULL;
                return "OK";
            } else if (cur->val == x && cur != head && cur == tail) {
                tail = tail->prev;
                tail->next = NULL;
                return "OK";
            } else if (cur->val == x && cur == head && cur == tail) {
                head = tail = NULL;
                return "OK";
            }
            cur = cur->prev;
        }
        return "ERROR";
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
    string s;
    st q;
    while(getline(fin, s)) {
        if (s[0] == '+') {
            s.erase(0, 1);
            q.plus(s);
        } else if (s[0] == '-') {
            s.erase(0, 1);
            if (q.minus(s) == "ERROR") {
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