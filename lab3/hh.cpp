#include <iostream>

using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;
    n -= 1;
    while (n != 0) {
        n /= 2;
        cnt++;
    }
    cout << cnt;
    return 0;
}