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
    int cnt;
    bst() {
        root = prev = NULL;
        cnt = 1;
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
        if (cur->left && cur->right) {
            cnt++;
        }
        if (cur->right) {
            print(cur->right);
        }
    }
};


int main() {
    bst a;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.add(x);
    }
    a.print();
    return 0;
}