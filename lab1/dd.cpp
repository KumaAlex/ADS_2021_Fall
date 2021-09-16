#include <iostream>

using namespace std;

struct st{
    string a[10000], b[10000], c[10000];
    int finisha, finishb, finishc;
    st() {
        finisha = -1;
        finishb = -1;
        finishc = -1;
    }
    void adda(string s) {
        finisha++;
        a[finisha] = s;
    }
    void addb(string s) {
        finishb++;
        b[finishb] = s;
    }
    void addc(string s) {
        finishc++;
        c[finishc] = s;
    }
    void show() {
        for (int i = 0; i <= finisha; i++) {
            cout << "9 " << a[i] << endl;
        }
        for (int i = 0; i <= finishb; i++) {
            cout << "10 " << b[i] << endl;
        }
        for (int i = 0; i <= finishc; i++) {
            cout << "11 " << c[i] << endl;
        }
    }
};

int main() {
    int n;
    string s;
    st q;
    while (cin >> n) {
        cin >> s;
        if (n == 9) {
            q.adda(s);
        }
        if (n == 10) {
            q.addb(s);
        }
        if (n == 11) {
            q.addc(s);
        }
    }
    q.show();
    return 0;
}