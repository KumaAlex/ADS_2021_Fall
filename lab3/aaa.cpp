#include <iostream>

using namespace std;


struct heap{
    int arr[1100];
    int hs;
    heap() {
        hs = 0;
    }

    void add(int x) {
        int i = hs;
        int p = (i-1)/2;
        hs++;
        arr[i] = x;
        while(i != 0 && arr[i] < arr[p]) {
            swap(arr[i], arr[p]);
            i = p;
            p = (i-1)/2;
        }
    }

    void print() {
        for (int i = 0; i < hs; i++) {
            cout << arr[i] << " ";
        }
    }
};

int main() {
    heap h;
    int n;
    cin >> n;
    
    return 0;
}