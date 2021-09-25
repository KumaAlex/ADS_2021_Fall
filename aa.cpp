#include <iostream>
#include <fstream>

using namespace std;


struct node{
    string name;
    int val;
    node * next;
    node * prev;
    node(string s, int x) {
        name = s;
        val = x;
        prev = NULL;
        next = NULL;
    }
};

struct st {
    node * head;
    node * tail;
    st() {
        head = NULL;
        tail = NULL;
    }
    void add(string s) {
        node * item = new node(s, 1);
        node * cur = head;
        while (cur != NULL) {
            if (cur->name == item->name) {
                cur->val += 1;
                return;
            }
            cur = cur->next;
        }
        if (head == NULL && tail == NULL) {
            tail = item;
        } else if (head == NULL && tail != NULL) {
            head = tail;
            tail = item;
            head->next = tail;
            tail->prev = head;
        } else {
            tail->next = item;
            item->prev = tail;
            tail = item;
        }
    }

    void out(ostream& fout) {
        node * cur = head;
        while (cur != NULL) {
            fout << cur->name << " " << cur->val << endl;
            cur = cur->next;
        }
    }

    bool sort(string a, string b) {
        int an = a.size(), bn = b.size(), min;
        if (an > bn) min = bn;
        else min = an;
        for (int i = 0; i < min; i++) {
            if (a[i] > b[i]) {
                return true;
            } else if (a[i] < b[i]) {
                return false;
            }
        }
        if (min == an) return false;
        else return true;
    }

    void sort() {
        node * curR = tail;
        node * curL = tail->prev;
        if (sort(curL->name, curR->name)) {
            if (curR == tail) {
                tail->prev = curL->prev;
                curL->prev->next = tail;
                tail->next = curL;
                curL->prev = tail;
                curL->next = NULL;
                tail = curL;
            } else if (curL == head) {
                head->next = curR->next;
                curR->next->prev = head;
                curR->prev = NULL;
                curR->next = head;
                head->prev = curR;
                head = curR; 
            } else {
                node * item = curL;
                item->next = curR->next;
                curR->next->prev = item;
                curR->prev = item
            }
        }
    }
};


int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    string s;
    st q;
    while(fin >> s) {
        q.add(s);
    }
    q.out(fout);
    fin.close();
    fout.close();
    return 0;
}