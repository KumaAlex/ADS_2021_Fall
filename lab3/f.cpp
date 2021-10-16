#include <iostream>

using namespace std;

struct st{
    int arr[105];
    int hs;
    st(){
        hs = 0;
    }
    void add(int x) {
        arr[hs] = x;
        hs++;
    }
    int maxi() {
        int ma = -1000;
        for (int i = 0; i < hs; i++) {
            if (ma < arr[i]) ma = arr[i];
        }
        return ma;
    }
    int mini() {
        int mi = 1000;
        for (int i = 0; i < hs; i++) {
            if (mi > arr[i]) mi = arr[i];
        }
        return mi;
    }
    void sw(int ma, int mi) {
        for (int i = 0; i < hs; i++) {
            if (arr[i] == ma) arr[i] = mi;
        }
    }
    void print() {
        for (int i = 0; i < hs; i++) {
            cout << arr[i] << " ";
        }
    }
};

int main() {
    st h;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        h.add(x);
    }
    int ma = h.maxi(), mi = h.mini();
    h.sw(ma, mi);
    h.print();
    return 0;
}