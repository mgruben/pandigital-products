#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

bool isPandigital(string s) {
    cout << s << endl;
    sort(begin(s), end(s));
    cout << s << endl;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != i+1 + '0') return false;
    }
    return true;
}

bool isUnusual(int n) {
    /* For each factor we find, n / (that factor) is itself
     * another factor, so add that to our sum as well.
     * 
     * Loop until i = sqrt(n), because this is the limit
     * for factors of n we haven't found yet.
     */ 
    for (int i = 1; i*i <= n; i++) {
        string s = to_string(n);
        if ((n % i) == 0) {
            s += to_string(i);
            s += to_string(n/i);
            if (isPandigital(s)) return true;
        }
    }
    return false;
}

int main() {
    cout << isPandigital("15234") << endl;
    return 0;
}
