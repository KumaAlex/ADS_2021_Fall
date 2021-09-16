#include <iostream>
using namespace std;

struct s{
    int a, b;
    void ans() {
        int c;
        c = b;
        if (a > b) c = a;
        while (c%a != 0 || c%b != 0) c++;
        cout << c;
    }
};

int main() {
    int a, b;
    s q;
    cin >> a >> b;
    q.a = a;
    q.b = b;
    q.ans();
    return 0;
}