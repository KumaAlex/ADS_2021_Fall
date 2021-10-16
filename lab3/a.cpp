#include <iostream>

using namespace std;

int main() {
    int n, x, m;
    cin >> n;
    int arr[1010];
    for (int i = 0; i < n; i++) {
        cin >> m;
        arr[i] = m;
    }
    cin >> x;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) cout << i+1 << " ";
    }
    return 0;
}