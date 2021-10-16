#include <iostream>

using namespace std;

int bs1(int arr[], int l, int r, int x){
    while(l <= r){
        int m = l + (r - l) / 2;
        if (arr[m] == x) {
            int j = m;
            while(arr[m] == arr[j]) {
                j--;
            }
            return j+1;
        }
        if (arr[m] < x){
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return -1;
}

int bs2(int arr[], int l, int r, int x){
    while(l <= r){
        int m = l + (r - l) / 2;
        if (arr[m] == x) {
            int j = m;
            while(arr[m] == arr[j]) {
                j++;
            }
            return j-1;
        }
        if (arr[m] < x){
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return -1;
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
        ch[i] = x;
    }
    for (int i = 0; i < k; i++) {
        cout << bs1(arr, 0, n-1, ch[i])+1;
        if (bs1(arr, 0, n-1, ch[i]) != -1) {
            cout << " " << bs2(arr, 0, n-1, ch[i])+1 << endl;
        } else {
            cout << endl;
        }
    }
    return 0;
}