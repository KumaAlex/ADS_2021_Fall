#include <iostream>

using namespace std;


struct st{
    int a[9999];
    int topIndex;
    st(){
        topIndex = -1;
    }
    void push(int n){
        topIndex++;
        a[topIndex] = n;
        cout << "ok" << endl;
    }
    void pop(){
        if(topIndex == -1) {
            cout << "error" << endl;
        } else {
            cout << a[topIndex] << endl;
            topIndex--;
        }
    }
    void back(){
        if(topIndex == -1) {
            cout << "error" << endl;
        } else {
            cout << a[topIndex] << endl;
        }
    }
    void size(){
        cout << topIndex + 1 << endl;
    }
    void clear(){
        topIndex = -1;
        cout << "ok" << endl;
    }
    void exit(){
        topIndex = -1;
        cout << "bye" << endl;
    }
};


int main(){
    st q;
    string s;
    while(cin >> s){
        if(s == "push") {
            int n;
            cin >> n;
            q.push(n);
        }
        if(s == "pop"){
            q.pop();
        }
        if(s == "back"){
            q.back();
        }
        if(s == "size"){
            q.size();
        }
        if(s == "clear"){
            q.clear();
        }
        if(s == "exit"){
            q.exit();
            break;
        }
    }

    return 0;
}