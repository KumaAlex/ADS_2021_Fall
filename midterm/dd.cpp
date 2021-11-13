#include <iostream>

using namespace std;




int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[i] = x;
    }
    int a, b;
    cin >> a >> b;
    int mas[a][b];
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            bool OK = true;
            int x;
            cin >> x;
            mas[i][j] = x;
        }
    }
    

    for (int k = 0; k < n; k++) {
            bool OK = true;
            for (int i = 0; i < a; i++) {
                for (int j = 0; j < b; j++) {
                    if (arr[k] == mas[i][j]) {
                        cout << i << " " << j << endl;
                        OK = false;
                    }
                }
            }
            if (OK) {
                cout << -1 << endl;
            }
        }
    return 0;
}