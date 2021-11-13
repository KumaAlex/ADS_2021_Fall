#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> ans;
    bool OK = true;
    string s, t;
    cin >> s >> t;
    int ns = s.size();
    int nt = t.size();
    for (int i = 0; i < ns-nt+1; i++) {
        int j = 0;
        if (s[i] == t[j]) {
            if (s.substr(i, nt) == t) {
                ans.push_back(i);
            }
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}