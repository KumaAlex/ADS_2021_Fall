#include <iostream>
#include <vector>

using namespace std;


vector<int> KMP(string s, int n) {
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

int main() {
    string s; cin >> s;
    int n = s.length();
    vector<int> res = KMP(s, n);
    int t = n - res[n - 1];
    if (n % t != 0) {
        cout << 1 << endl;
    } else {
        cout << n / t << endl; 
    }
    return 0;
}