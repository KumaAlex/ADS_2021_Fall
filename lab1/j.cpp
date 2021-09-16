#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int c;

    if (a - b < 0) c = a;
    else c = b;
    if (a%c == 0 && b%c == 0) {
        cout << c;
        return 0;
    }

    c += 1;
    c /= 2;

    while (a%c != 0 || b%c != 0) {
        c--;
    }

    cout << c;
    return 0;
}