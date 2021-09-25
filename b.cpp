#include <iostream>
#include <fstream>

using namespace std;

void f(ostream& stream, string a) {
    stream << a;
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    string a;
    while (fin>>a) {
        f(fout, a);
    }
    fin.close();
    fout.close();
    return 0;
}