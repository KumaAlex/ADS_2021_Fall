#include <iostream>

using namespace std;


void heapify(int arr[], int n, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l < n && arr[l] > arr[largest])
        largest = l;
    
    if(r < n && arr[r] > arr[largest])
        largest = r;
    
    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void true_heap(int arr[], int n) {
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void print(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}

void find(int arr[], int n, int ans[], int k) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            if (arr[i] == ans[j]) {
                cout << i+1 << endl;
            }
        }
    }
}

int main() {
    int n, k;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[i] = x;
    }
    cin >> k;
    int ans[k];
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        arr[a-1] += b;
        ans[i] = arr[a-1];
    }
    true_heap(arr, n);
    find(arr, n, ans, k);
    print(arr, n);
    return 0;
}