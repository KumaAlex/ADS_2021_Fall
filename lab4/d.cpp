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
    node * prev;
    bst() {
        root = prev = NULL;
    }


    node * add(node* root, int x) {
		if (root == NULL) {
			return new node(x);	
		}
		if (root->val > x) {
			root->left = add(root->left, x);
		} else if (root->val < x) {
			root->right = add(root->right, x);
		}
		return root;
	}
    void add(int x) {
		root = add(root, x);
	}
    void print() {
        print(root);
    }
    void print(node * cur) {
        if (cur->left) {
            print(cur->left);
        }
        cout << cur->val << endl;
        if (cur->right) {
            print(cur->right);
        }
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