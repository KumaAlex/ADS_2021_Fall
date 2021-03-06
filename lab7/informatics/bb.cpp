#include <iostream>
#include <vector>

using namespace std;

vector<int> f(string s, int n){
   vector<int> p(n);
   for(int i = 1; i < n; ++i){
       int j = p[i-1];
       while(j > 0 && s[i] != s[j]){
           j = p[j - 1];
       }
       if(s[i] == s[j]) j++;
       p[i] = j;
   }
   return p;
}


int main(){

    string s;
    cin >> s;
    int n = s.size();

    vector<int> pi = f(s, n);

    int t = n-pi[n-1];

    if (n%t != 0) {
        cout << '1';
    } else {
        cout << n/t;
    }

    return 0;
}