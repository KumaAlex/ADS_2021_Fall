#include <iostream>
#include <fstream>

using namespace std;

struct node {
    string s;
    int val;
    node(string s, int val) {
        val = val;
        s = s;
    }
};

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    string s;
    st q;
    while(getline(fin, s)) {
        if (s[0] == '+') {
            s.erase(0, 1);
            q.plus(s);
        } else if (s[0] == '-') {
            s.erase(0, 1);
            if (q.minus(s) == "ERROR") {
                fout << "ERROR";
                return 0;
            }
        }
    }
    return 0;
}