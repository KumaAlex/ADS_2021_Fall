#include <iostream>

using namespace std;

struct de {
    int finish, start;
    int a[10000];
    de(){
        finish = 5000;
        start = 5001;
    }
    void push_back(int n){
        finish++;
        a[finish] = n;
    }
    void pop_front() {
        start++;
    }
    int front() {
        return a[start];
    }
    int size() {
        int h;
        h = finish - start;
        return h+1;
    }
};


int main() {
    int count = 0;
    de p1, p2;
    for (int i = 0; i < 5; i++) {
        int n;
        cin >> n;
        p1.push_back(n);
    }
    for (int i = 0; i < 5; i++) {
        int n;
        cin >> n;
        p2.push_back(n);
    }

    while (p1.size() != 0 && p2.size() != 0) {
        if (count == 1000000) {
            cout << "botva";
            return 0;
        }
        count++;
        if (p1.front() == 0 && p2.front() == 9) {
            p1.push_back(p1.front());
            p1.push_back(p2.front());
            p1.pop_front();
            p2.pop_front();
        }
        else if (p1.front() == 9 && p2.front() == 0) {
            p2.push_back(p1.front());
            p2.push_back(p2.front());
            p1.pop_front();
            p2.pop_front();
        } else {
            if (p1.front() > p2.front()) {
                p1.push_back(p1.front());
                p1.push_back(p2.front());
                p1.pop_front();
                p2.pop_front();
            } else if (p1.front() < p2.front()) {
                p2.push_back(p1.front());
                p2.push_back(p2.front());
                p1.pop_front();
                p2.pop_front();
            }
        }
    }
    if (p1.size() == 0) {
        cout << "second " << count;
    } else {
        cout << "first " << count;
    }
    return 0;
}