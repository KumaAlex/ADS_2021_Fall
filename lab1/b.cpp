#include <iostream>

using namespace std;


struct qu{
    int a[999999];
    int start, finish;
    qu(){
        start = 0;
        finish = 0;
    }
    void push(int n){
        a[finish] = n;
        finish++;
        cout << "ok" << endl;
    }
    void pop(){
        if (finish == start) cout << "error" << endl;
        else {
            cout << a[start] << endl;
            start++;
        }
    }
    void front(){
        if (start == finish) cout << "error" << endl;
        else cout << a[start] << endl;
    }
    void clear(){
        finish = 0;
        start = 0;
        cout << "ok" << endl;
    }
    void size(){
        cout << finish - start << endl;
    }
};


int main() {
    qu q;
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
        if(s == "front"){
            q.front();
        }
        if(s == "size"){
            q.size();
        }
        if(s == "clear"){
            q.clear();
        }
        if(s == "exit"){
            cout << "bye" << endl;
            break;
        }
    }

    return 0;
}