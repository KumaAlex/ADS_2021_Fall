#include <iostream>

using namespace std;

struct node
{
    int val;
    node * left;
    node * right;
    node(int x) {
        val = x;
        left = right = NULL;
    }
};


struct bst
{
    node * root;
    int size;
    int arr[1000000];
    bst() {
        root = NULL;
        size = -1;
    }

    void add(int x) {
        root = add(root, x);
    }

    node * add (node * cur, int x) {
        if (cur == NULL) {
            return new node(x);
        }
        if (cur->val > x) {
            cur->left = add(cur->left, x);
        }
        if (cur->val < x) {
            cur->right = add(cur->right, x);
        }
        return cur;
    }

    void print() {
        print(root);
    }

    void print(node * cur) {
        if (cur->left) {
            print(cur->left);
        }
        size++;
        arr[size] = cur->val;
        if (cur->right) {
            print(cur->right);
        }
    }
    string bal() {
        for (int i = 0; i < size; i++) {
            if (arr[i+1] - arr[i] != 1) {
                return "NO";
            }
        }
        return "YES";
    }
};


int main() {
    int x;
    bst a;
    while (cin >> x) {
        if (x == 0) break;
        a.add(x);
    }
    a.print();
    cout << a.bal();
    return 0;
}