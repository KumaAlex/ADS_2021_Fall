#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> v1;
    vector<string> v2;
    vector<string> v3;
    int n;
    string s;
    while (cin >> n) {
        cin >> s;
        if (n == 9) {
            v1.push_back(s);
        }
        if (n == 10) {
            v2.push_back(s);
        }
        if (n == 11) {
            v3.push_back(s);
        }
    }
    int c1, c2, c3;
    c1 = v1.size();
    c2 = v2.size();
    c3 = v3.size();
    for (int i = 0; i < c1; i++) {
        cout << 9 << " " << v1[i] << endl;
    }
    for (int i = 0; i < c2; i++) {
        cout << 10 << " " << v2[i] << endl;
    }
    for (int i = 0; i < c3; i++) {
        cout << 11 << " " << v3[i] << endl;
    }
    return 0;
}