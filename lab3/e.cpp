#include <iostream>

using namespace std;

int main() {
    int n, gold=0, sil=0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[i] = x;
        if (x > gold) gold = x;
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] > sil && arr[i] != gold) {
            sil = arr[i];
        }
    }
    cout << sil;
    return 0;
}