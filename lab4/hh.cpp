#include <iostream>

using namespace std;

struct node{
    int val;
    node * left;
    node * right;
    node(int x){
        val = x;
        right = left = NULL;
    }
};

struct bt{
    node * root;
    bt() {
        root = NULL;
    }

    void add(int x) {
        root = add(root, x);
    }
    node * add(node * cur, int x) {
        if (cur == NULL) {
            return new node(x);
        }
        if (cur->val < x) {
            cur->right = add(cur->right, x);
        }
        if (cur->val > x) {
            cur->left = add(cur->left, x);
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
        cout << cur->val << " ";
        if (cur->right) {
            print(cur->right);
        }
    }    
};

int main() {
    bt q;
    int arr[] = {1, 8, 2 ,7 ,3 ,6, 4, 5};
    int n = 8;
    for (int i = 0; i < n; i++) {
        q.add(arr[i]);
    }
    q.print();
    return 0;
}