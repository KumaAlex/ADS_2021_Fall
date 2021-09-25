#include <iostream>

using namespace std;

struct node{
    int val;
    node * right;
    node * left;
    node(int x) {
        val = x;
        right = left = NULL;
    }
};

struct bst{
    node * root;
    int cnt;
    bst() {
        root = NULL;
        cnt = 0;
    }


    node * add(node * cur, int x) {
        if (cur == NULL) return new node(x);
        if (cur->val < x) {
            cur->right = add(cur->right, x);
        }
        if (cur->val > x) {
            cur->left = add(cur->left, x);
        }
        return cur;
    }
    void add(int x) {
        node * res = add(root, x);
        if (root == NULL) root = res;
    }

    int print(node * current, int level){
        if(current != NULL){
            if (cnt < level) cnt = level;
            print(current->left, level + 1);
            print(current->right, level + 1);
        }
        return cnt;
    }
    void print(){
        cout << print(root, 1);
        cout << endl;
    }


};


int main() {
    bst a;
    int n;
    while (cin >> n) {
        if (n == 0) break;
        a.add(n);
    }
    
    a.print();
    return 0;
}