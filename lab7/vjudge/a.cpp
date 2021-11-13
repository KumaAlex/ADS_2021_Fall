#include <iostream>
#include <vector>
#include <set>

using namespace std;



set<string> KMP(string s) {
    set<string> st;
    int n = s.length();
    vector<int> p(n);
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && s[i] != s[j]) {
            j = p[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        p[i] = j;
        st.insert(s.substr(i, j+s.size()));
    }
    return st;
}

void f() {
    string s;
    cin >> s;
    set<string> ans = KMP(s);
    cout << ans.size() << endl << endl;
    set<string> :: iterator it = ans.begin();
    while (it != ans.end()) {
        cout << *it << " ";
        it++;
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        f();
    }
}