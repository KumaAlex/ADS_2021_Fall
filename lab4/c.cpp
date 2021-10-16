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

    node * rightmost(node * cur) {
        while (cur->right) {
            cur = cur->right;
        }
        return cur;
    }

    node* second_maximum(node* root) {
		if (root->right != NULL) { // если у корня имеется правое поддерево
			node* parent = root; // храним указатель на родителя самого правого ребенка
			while (parent->right->right != NULL) { // находим этого родителя
				parent = parent->right;
			}
			
			node* right = parent->right; // берем указатель на самого правого ребенка в дереве
			if (right->left == NULL) { // если у right нет левого поддерева
				return parent; // возвращаем родителя, так как он самый близкий, меньший по значению
			}
			return rightmost(right->left); // иначе идем в левое поддерево, и там ищем самое близкое значение к максимальному
		} 
		return rightmost(root->left); // если у корня нет правого поддерева, возвращаем, самое большое значение в левом поддереве
	}
    
    void sec_rightmost() {
        cout << second_maximum(root)->val;
    }

};


int main() {
    bst a;
    int n;
    while (cin >> n) {
        if (n == 0) break;
        a.add(n);
    }
    a.sec_rightmost();
    return 0;
}