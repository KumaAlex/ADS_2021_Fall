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
        if(tail == NULL && head == NULL) {
            head = tail = item;
        } else {
            node * cur = head;
            while (cur != NULL) {
                if(cur->name == item->name) {
                    cur->val += 1;
                    return;
                }
                cur = cur->next;
            }
            tail->next = item;
            item->prev = tail;
            tail = item;
        }
    }

    void order() {
        node * test = tail;
        bool OK = false;
        while (test->prev != NULL) {
            node * cur = test;
            node * precur = test->prev;
            if (test->val == test->prev->val){
                cur = test;
                precur = test->prev;
                int i = 0;
                while (cur->name[i] == precur->name[i]) i++;
                if (cur->name[i] < precur->name[i] && cur != tail && precur != head) {
                    precur->prev->next = cur;
                    cur->prev = precur->prev;
                    cur->next->prev = precur;
                    precur->next = cur->next;
                    cur->next = precur;
                    precur->prev = cur;
                    OK = true;
                } else if (cur->name[i] < precur->name[i] && cur == tail && precur != head) {
                    precur->prev->next = cur;
                    cur->prev = precur->prev;
                    cur->next = precur;
                    precur->prev = cur;
                    precur->next = NULL;
                    tail = precur;
                    OK = true;
                } else if (cur->name[i] < precur->name[i] && cur != tail && precur == head) {
                    precur->next = cur->next;
                    cur->next->prev = precur;
                    precur->prev = cur;
                    cur->next = precur;
                    cur->prev = NULL;
                    head = cur;
                    OK = true;
                } else if (cur->name[i] < precur->name[i] && cur == tail && precur == head) {
                    head = cur;
                    tail = precur;
                    head->prev = NULL;
                    tail->next = NULL;
                    head->next = tail;
                    tail->prev = head;
                    OK = true;
                }
            }
            test = test->prev;
            if (OK) {
                OK = false;
                test = tail;
            }
        }
    }


    void sort() {
        node * test = tail;
        node * cur = test;
        node * precur = test->prev;
        if (tail->prev != NULL) {
            test = tail;
            while (1 == 1) {
                cur = test;
                precur = test->prev;
                if (precur == NULL) return;
                if(cur->val > precur->val && cur != tail && precur != head){
                    precur->prev->next = cur;
                    cur->prev = precur->prev;
                    cur->next->prev = precur;
                    precur->next = cur->next;
                    cur->next = precur;
                    precur->prev = cur;
                    test = tail;
                } else if (cur->val > precur->val && cur == tail && precur != head) {
                    precur->prev->next = cur;
                    cur->prev = precur->prev;
                    cur->next = precur;
                    precur->prev = cur;
                    precur->next = NULL;
                    tail = precur;
                    test = tail;
                } else if (cur->val > precur->val && cur != tail && precur == head) {
                    precur->next = cur->next;
                    cur->next->prev = precur;
                    precur->prev = cur;
                    cur->next = precur;
                    cur->prev = NULL;
                    head = cur;
                    return;
                } else if (cur->val > precur->val && cur == tail && precur == head) {
                    head = cur;
                    tail = precur;
                    head->prev = NULL;
                    tail->next = NULL;
                    head->next = tail;
                    tail->prev = head;
                    return;
                }
                test = test->prev;
            }
        }
    }

    void out(ostream& fout) {
        node * cur = head;
        while (cur != NULL) {
            fout << cur->name << " " << cur->val << endl;
            cur = cur->next;
        }
    }

    void show() {
        node * cur = head;
        cout << endl << endl;
        while (cur != NULL) {
            cout << cur->name << " " << cur->val << endl;
            cur = cur->next;
        }
        
        cout << endl << endl;
    }
};


int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    string s;
    st q;
    while(fin >> s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '.' || s[i] == ',' || s[i] == ':' || s[i] == ';' || s[i] == '!' || s[i] == '?') {
                s.erase(i, 1);
            }
            if (s[i] <= 'Z') {
                s[i] -= 'A' - 'a';
            }
        }
        q.add(s);
        q.sort();
    }
    q.order();
    q.out(fout);
    fin.close();
    fout.close();
    return 0;
}