#include <iostream>

using namespace std;

int main() {
    int k, m, x, cnt = 0;
    cin >> k >> m;
    int arr[k][m];
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            cin >> x;
            arr[i][j] = x;
        }
    }
    
    for (int j = 0; j < m; j++) {
        int a = -100000, b = 100000;
        for (int i = 0; i < k; i++) {
            if (arr[i][j] > a) {
                a = arr[i][j];
            }
        }
        for (int i = 0; i < k; i++) {
            if (arr[i][j] == a) {
            for (int p = 0; p < m; p++) {
                if (arr[i][p] < b) b = arr[i][p];
                }
            }
            if (a == b) {
                cnt++;
            }
            b = 100000;
        }
    }

    cout << cnt;

    return 0;
}