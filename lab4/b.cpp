#include <iostream>

using namespace std;

struct node{
    int val;
    node * left;
    node * right;
    node(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

struct bst{
    node * _root;
    int count;

    node * add(node * current, int x){
        if(current == NULL) return new node(x);

        if(current->val < x){
            current->right = add(current->right, x);
        }

        if(current->val > x){
            current->left = add(current->left, x);
        }

        return current;
    }

    bst(){
        _root = NULL;
        count = 0;
    }

    void add(int x){
        node * res = add(_root, x);
        if(_root == NULL){
            _root = res;
        }
    }

    void cnt(){
        cout << cnt(_root);
    }
    int cnt(node * current){
        if (current->left) {
            cnt(current->left);
        }
        count++;
        if (current->right) {
            cnt(current->right);
        }
        return count;
    }
};

int main(){
    bst tree;

    int x;
    while (cin >> x) {
        if (x == 0) break;
        tree.add(x);
    }
    
    tree.cnt();

    return 0;
}