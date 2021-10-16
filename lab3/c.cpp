#include <iostream>

using namespace std;

int main() {
    int n, x = -1000, m, j;
    cin >> n;
    int arr[1010];
    for (int i = 0; i < n; i++) {
        cin >> m;
        arr[i] = m;
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] > x) {
            j = i;    
            x = arr[i];
        }
    }
    cout << j+1;
    return 0;
}