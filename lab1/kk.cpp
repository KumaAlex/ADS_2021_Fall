#include <iostream>
#include <cmath>

using namespace std;

struct st{
    int n;
    void ans() {
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                cout << "composite";
                return;
            }
        }
        cout << "prime";
    }
};

int main() {
    st s;
    int n;
    cin >> n;
    s.n = n;
    s.ans();
    return 0;
}