#include <iostream>
#include <set>

using namespace std;

void f() {
    string s;
    cin >> s;
    int n = s.size();
    set<string> st;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            st.insert(s.substr(i, j));
        }
    }
    cout << st.size() << endl;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        f();
    }
    return 0;
}