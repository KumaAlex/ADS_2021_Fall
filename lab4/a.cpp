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
    }

    void add(int x){
        node * res = add(_root, x);
        if(_root == NULL){
            _root = res;
        }
    }


    void lvl(){
        cout << lvl(_root);
    }

    int lvl(node * current){
        int a = 0, b = 0;
        if (current->left) {
            a = lvl(current->left);
        }
        if (current->right) {
            b = lvl(current->right);
        }
        return max(a, b) + 1;
    }
};

int main(){
    bst tree;

    int x;
    while (cin >> x) {
        if (x == 0) break;
        tree.add(x);
    }
    
    tree.lvl();

    return 0;
}