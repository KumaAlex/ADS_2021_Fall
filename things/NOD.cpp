#include <iostream>

using namespace std;

int NOD(int a, int b)
{
    while(a > 0 && b > 0)
 
        if(a > b)
            a %= b;
 
        else
            b %= a;
 
    return a + b;
}

int NOK(int a, int b) { 
    int mul = a*b;
    int nod = NOD (a, b);
    return mul/nod; 
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << NOD(a, b);
    cout << endl << NOK(a, b);
    return 0;
}