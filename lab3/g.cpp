#include <iostream>

using namespace std;

string bs(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x) return "YES";
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return "NO";
}

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n], ch[k];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[i] = x;
    }
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        cout << bs(arr, 0, n-1, x) << endl;
    }
    return 0;
}