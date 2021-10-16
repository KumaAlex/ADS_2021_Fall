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

    void print(){
        print(_root, 0);
    }

    void lvl(){
        cout << lvl(_root);
    }

    void print(node * current, int level){
        if(current != NULL){
            print(current->left, level + 1);
            cout << current->val << " " << level << endl;
            print(current->right, level + 1);
        }
    }

    int lvl(node * current){
        int a = 0, b = 0;
        if (current->left) {
            a = lvl(current->left);
            cout << current->val << endl;
        }
        if (current->right) {
            b = lvl(current->right);
            
            cout << current->val << endl;
        }
        return max(a, b) + 1;
    }

    void pr(node * cur) {
        if (cur->left) {
            pr(cur->left);
        }
        cout << cur->val << " ";
        if (cur->right) {
            pr(cur->right);
        }
    }

    void pr(){
        pr(_root);
    }
};

int main(){
    bst tree;

    int x;
    while (cin >> x) {
        if (x == 0) break;
        tree.add(x);
    }
    
    tree.pr();

    return 0;
}