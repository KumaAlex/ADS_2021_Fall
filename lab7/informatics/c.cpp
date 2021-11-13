#include <iostream>

using namespace std;

int main() {
    string s, t, cur;
    cin >> s >> t;
    cur = s;
    int n = s.size();
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (cur == t) {
            cout << j;
            return 0;
        }
        cur = cur[n-1] + cur.substr(0, n-1);
        j++;
    }
    cout << -1;
    return 0;
}