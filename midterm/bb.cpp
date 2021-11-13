#include <iostream>

using namespace std;



void merge(long arr[], int l, int m, int r) {
    int size1, size2;
    size2 = r - m;
    size1 = m - l + 1;

    int arr1[size1], arr2[size2];

    for (int i = 0; i < size1; i++) {
        arr1[i] = arr[l+i];
    }
    for (int i = 0; i < size2; i++) {
        arr2[i] = arr[m+i+1];
    }

    int i=0, j=0, k=l;

    while (i < size1 && j < size2) {
        if (arr1[i] >= arr2[j]) {
            arr[k] = arr1[i];
            i++;
        } else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while(i < size1){
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while(j < size2){
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void ms(long arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l)/2;
        ms(arr, l, m);
        ms(arr, m+1, r);
        merge(arr, l, m, r);
    }
}



int main() {
    long n;
    long sum = 0;
    cin >> n;
    long arr[n];
    for (long i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[i] = x;
    }
    while (n != 1) {
        ms(arr, 0, n-1);
        arr[n-2] = arr[n-2] + arr[n-1];
        n--;
        sum += arr[n-1];
    }
    cout << sum;

    return 0;
}