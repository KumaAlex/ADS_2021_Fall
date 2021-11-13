#include <iostream>

using namespace std;

int partition(int l, int r, int arr[]) {
    int j = l;
    for (int i = l; i < r; ++i) {
        if (arr[i] < arr[r]) {
            swap(arr[j], arr[i]);
            j++;
        }
    }
    swap(arr[j], arr[r]);
    return j;
}

void quick_sort(int l, int r, int arr[]) {
    if (l >= r) {
        return;
    }
    int p = partition(l, r, arr);
    quick_sort(l, p - 1, arr);
    quick_sort(p + 1, r, arr);
}


int main () {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[i] = x;
    }
    quick_sort(0, n-1, arr);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}