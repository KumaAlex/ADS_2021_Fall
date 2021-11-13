#include <iostream>

using namespace std;


void heapify(int arr[], int n, int i) {
    int larg = i;
    int c1 = i * 2 + 1;
    int c2 = i * 2 + 2;
    if (c1 < n && arr[c1] > arr[larg]) {
        larg = c1;
    }
    if (c2 < n && arr[c2] > arr[larg]) {
        larg = c2;
    }
    
    if (larg != i) {
        swap(arr[larg], arr[i]);
        heapify(arr, n, larg);
    }
}

void true_heap(int arr[], int n) {
    for(int i = n/2-1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void hs(int arr[], int n) {
    for(int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
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
    true_heap(arr, n);
    print(arr, n);
    hs(arr, n);
    print(arr, n);

    return 0;
}