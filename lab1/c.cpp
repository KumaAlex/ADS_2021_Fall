#include <iostream>

using namespace std;


struct de {
    int finish, start;
    int a[999999];
    de(){
        finish = 555555;
        start = 555556;
    }
    void push_b(int n){
        cout << "ok" << endl;
        finish++;
        a[finish] = n;
    }
    void push_f(int n){
        cout << "ok" << endl;
        start--;
        a[start] = n;
    }
    int size() {
        int h;
        h = finish - start;
        return h+1;
    }
    void pop_b(int count) {
        if (count <= 0) cout << "error" << endl;
        else {
            cout << a[finish] << endl;
            finish--;
        } 
    }
    void pop_f(int count) {
        if (count <= 0) cout << "error" << endl;
        else {
            cout << a[start] << endl;
            start++;
        }
    }
    void clear() {
        finish = 555555;
        start = 555556;
        cout << "ok" << endl;
    }
    void front(int count) {
        if (count <= 0) cout << "error" << endl;
        else {
            cout << a[start] << endl;
        }
    }
    void back(int count) {
        if (count <= 0) cout << "error" << endl;
        else {
            cout << a[finish] << endl;
        }
    }
};

int main() {
    de q;
    string s;
    int n;
    while (cin >> s) {
        if (s == "push_back") {
            cin >> n;
            q.push_b(n);
        }
        if (s == "push_front") {
            cin >> n;
            q.push_f(n);
        }
        if (s == "exit") {
            cout << "bye" << endl;
            break;
        }
        if (s == "size") {
            cout << q.size() << endl;
        }
        if (s == "pop_back") {
            int count = q.size();
            q.pop_b(count);
        }       
        if (s == "pop_front") {
            int count = q.size();
            q.pop_f(count);
        }
        if (s == "back") {
            int count = q.size();
            q.back(count);
        }       
        if (s == "front") {
            int count = q.size();
            q.front(count);
        }       
        if (s == "clear") {
            q.clear();
        }
        
    }
    return 0;
}
