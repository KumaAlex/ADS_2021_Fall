#include <iostream>

using namespace std;

int main() {
    string s;
    int n = 0;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        n *= 10;
        n += s[i] - '0'; 
    }
    cout << n;
    return 0;
}