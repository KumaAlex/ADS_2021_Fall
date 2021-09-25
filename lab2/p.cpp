#include <iostream>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    if (a[0] == b[0]) {
        int i = 0;
        while (a[i] != b[i]) i++;
        if (a[i] > b[i]) {
            cout << a;
        } else {
            cout << b;
        }
    }
    cout << b.size();
    return 0;
}