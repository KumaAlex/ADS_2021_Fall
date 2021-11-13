#include <iostream>

using namespace std;


int partition(int arr[], int l, int r) {
    int j = l;
    for (int i = l; i < r; i++) {
        if (arr[i] < arr[r]) {
            swap(arr[j], arr[i]);
            j++;
        }
    }
    swap(arr[j], arr[r]);
    return j;
}

void qs(int arr[], int l, int r) {
    if(l<r) {
        int piv = partition(arr, l, r);
        qs(arr, piv+1, r);
        qs(arr, l, piv-1);
    }
}

void print(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 51, 6, 7};
    int n = sizeof(arr) / sizeof(int);

    print(arr, n);
    qs(arr, 0, n-1);
    print(arr, n);

    return 0;
}