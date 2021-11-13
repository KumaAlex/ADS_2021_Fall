#include <iostream>

using namespace std;


struct node {
    int sum;
    node * next;
    node * prev;
    int arr[510];
    node(int mas[], int summ, int n) {
        for (int i = 0; i < n; i++) {
            arr[i] = mas[i];
        }
        next = prev = NULL;
        sum = summ;
    }
};


struct st{
    node * head;
    node * beg;
    st() {
        head = beg = NULL;
    }
    void add(int mas[], int sum, int n) {
        node * cur = new node(mas, sum, n);
        if (head == NULL && beg == NULL) {
            head = cur;
            beg = cur;
            return;
        }
        head->next = cur;
        cur->prev = head;
        head = cur;
    }
    void sort() {
        node * cur = head;
        while (cur->prev != NULL) {
            node * c1 = cur;
            node * c2 = cur->prev;
            if (c1->sum > c2->sum && c2->prev != NULL && c1->next != NULL) {
                node * r = c1->next;
                node * l = c2->prev;
                c1->next = c2;
                c2->prev = c1;
                c1->prev = l;
                c2->next = r;
            } else if (c1->sum > c2->sum && c2->prev == NULL && c1->next != NULL) {
                node * r = c1->next;
                c1->next = c2;
                c2->prev = c1;
                c2->next = r;
                beg = c1;
                cur = head;
                beg->prev = NULL;
            } else if (c1->sum > c2->sum && c2->prev != NULL && c1->next == NULL) {
                node * l = c2->prev;
                c1->next = c2;
                c2->prev = c1;
                c1->prev = l;
                c2->next = NULL;
                head = c2;
                cur = head;
            } else if (c1->sum > c2->sum && c2->prev == NULL && c1->next == NULL) {
                c1->next = c2;
                c2->prev = c1;
                head = c2;
                beg = c1;
                beg->prev = NULL;
                head->next = NULL;
                cur = head;
            }
            if (c1->sum == c2->sum) {
                int j=0;
                while (c1->arr[j] == c2->arr[j]) j++;
                    if (c1->arr[j] < c2->arr[j] && c2->prev != NULL && c1->next != NULL) {
                    node * r = c1->next;
                    node * l = c2->prev;
                    c1->next = c2;
                    c2->prev = c1;
                    c1->prev = l;
                    c2->next = r;
                } else if (c1->arr[j] < c2->arr[j] && c2->prev == NULL && c1->next != NULL) {
                    node * r = c1->next;
                    c1->next = c2;
                    c2->prev = c1;
                    c2->next = r;
                    beg = c1;
                    cur = head;
                    beg->prev = NULL;
                } else if (c1->arr[j] < c2->arr[j] && c2->prev != NULL && c1->next == NULL) {
                    node * l = c2->prev;
                    c1->next = c2;
                    c2->prev = c1;
                    c1->prev = l;
                    head = c2;
                    head->next = NULL;
                    cur = head;
                } else if (c1->arr[j] < c2->arr[j] && c2->prev == NULL && c1->next == NULL) {
                    c1->next = c2;
                    c2->prev = c1;
                    head = c2;
                    beg = c1;
                    beg->prev = NULL;
                    head->next = NULL;
                    cur = head;
                }
            }
            cur = cur->prev;
        }
    }

    void print(int n) {
        node * cur = beg;
        while (cur != NULL) {
            for (int i = 0; i < n; i++) {
                cout << cur->arr[i] << " ";
            }
            cout << endl;
            cur = cur->next;
        }
    }

};



int main() {
    int n, m;
    st q;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++) {
        int mas[m], sum = 0;
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            mas[j] = x;
            sum += x; 
        }
        q.add(mas, sum, m); 
        q.sort();
    }
    q.print(m);

    return 0;
}