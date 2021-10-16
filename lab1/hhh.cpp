#include <iostream>

using namespace std;


struct qu{
    int a[99999];
    int start, finish;
    qu(){
        start = 0;
        finish = 0;
    }
    void push(int n){
        a[finish] = n;
        finish++;
    }
    void pop(){
        if (finish == start) cout << "error" << endl;
        else {
            cout << a[start] << endl;
            start++;
        }
    }
    void supergob(int p) {
        int size = (finish - start)/2;
        for (int i = finish; i > (finish - size); i--) {
            a[i] = a[i - 1];
        }
        a[finish - size] = p;
        finish++;
    }
};



int main() {
    int n;
    cin >> n;
    qu q;
    for (int i = 0; i < n; i++) {
        char c;
        int a;
        cin >> c;
        if (c == '-') {
            q.pop();
        }
        if (c == '+') {
            cin >> a;
            q.push(a);
        }
        if (c == '*') {
            cin >> a;
            q.supergob(a);
        }
    }
    return 0;
}