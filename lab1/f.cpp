#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<char> q;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            q.push(s[i]);
        } else {
            if (q.size() == 0) {
                cout << "no";
                return 0;
            }
            if (s[i] == ')' && q.top() == '(') q.pop();
            else if (s[i] == ']' && q.top() == '[') q.pop();
            else if (s[i] == '}' && q.top() == '{') q.pop();
            else {
                cout << "no";
                return 0;
            }
        }
    }
    if (q.size() != 0) {
        cout << "no";
        return 0;
    }
    cout << "yes";
    return 0;
}