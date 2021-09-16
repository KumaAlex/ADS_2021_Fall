#include <iostream>
#include <stack>


using namespace std;

int main() {
    stack<int> s;
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