#include <iostream>
#include <vector>

using namespace std;



vector<int> KMP(string s) {
    int n = s.length();
    vector<int> p(n);
    int j = 0;
    for (int i = 1; i < n; i++) {
        while (j > 0 && s[i] != s[j]) {
            j = p[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        p[i] = j;
    }
    return p;
}

void f() {
    string s, t;
    cin >> s >> t;
    vector<int> res = KMP(t + "#" + s);
    int n = t.size();

    vector<int> ans;
    for (int i = 0; i < res.size(); i++) {
        int x = res[i];
        if (x == n) {
            ans.push_back(i + 1 - 2*n);
        }
    }
    if (ans.empty()) {
        cout << "Not Found" << endl << endl;
        return;
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl << endl;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        f();
    }
}