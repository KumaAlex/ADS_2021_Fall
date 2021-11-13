#include <iostream>

using namespace std;


void merge(int arr[], int l, int m, int r) {
    int s1 = m-l+1;
    int s2 = r-m;
    int arr1[s1], arr2[s2];

    
    for (int i = 0; i < s1; i++) {
        arr1[i] = arr[l+i];
    }
    for (int i = 0; i < s2; i++) {
        arr2[i] = arr[m+1+i];
    }

    

    int i = 0, j = 0, k = l;

    while (i < s1 && j < s2) {
        if (arr1[i] <= arr2[j]) {
            arr[k] = arr1[i];
            i++;
        } else {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while(i < s1){
        arr[k] = arr1[i];
        i++;
        k++;
    }

    while(j < s2){
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void ms(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l)/2;
        ms(arr, l, m);
        ms(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int n = 5;
    int arr[] = {1, 5, 2, 4, 3};
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    ms(arr, 0, n-1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}