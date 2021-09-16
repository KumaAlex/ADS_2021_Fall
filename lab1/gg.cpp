#include <iostream>

using namespace std;


struct st{
    int a[99999];
    int topIndex;
    st(){
        topIndex = -1;
    }
    void push(int n){
        topIndex++;
        a[topIndex] = n;
    }
    void pop(){
        topIndex--;
    }
    int top(){
        return a[topIndex];
    }
    int size(){
        return topIndex+1;
    }
    void clear(){
        topIndex = -1;
    }
};

int main() {
    st s;
    string a;
    getline(cin, a);
    for (int i = 0; i < a.size(); i++) {
        if (a[i] >= '0' && a[i] <='9') {
            s.push(a[i] - '0');
        }
        if (a[i] == '-') {
            int n1, n2;
            n2 = s.top();
            s.pop();
            n1 = s.top();
            s.pop();
            s.push(n1 - n2);
        }
        if (a[i] == '+') {
            int n1, n2;
            n2 = s.top();
            s.pop();
            n1 = s.top();
            s.pop();
            s.push(n1 + n2);
        }
        if (a[i] == '*') {
            int n1, n2;
            n2 = s.top();
            s.pop();
            n1 = s.top();
            s.pop();
            s.push(n1 * n2);
        }
    }
    cout << s.top();

    return 0;
}