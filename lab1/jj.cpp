#include <iostream>

using namespace std;

struct st {
    int c, a, b;
    void NOK() {
        if (a - b < 0) c = a;
        else c = b;
        if (a%c == 0 && b%c == 0) {
            cout << c;
            return;
        }

        c += 1;
        c /= 2;

        while (a%c != 0 || b%c != 0) {
            c--;
        }

        cout << c;
    }
};

int main() {
    st s;
    int a, b;
    cin >> a >> b;
    s.a = a;
    s.b = b;
    s.NOK();
    return 0;
}