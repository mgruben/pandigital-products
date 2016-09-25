#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * Given a string of digits of length n, return true if those
 * digits are 1 through n, exactly once.
 * 
 * Otherwise, return false.
 */
bool isPandigital(string s) {
    sort(begin(s), end(s));
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != i+1 + '0') return false;
    }
    return true;
}

/**
 * Given a number n, return true if there is some factorization
 * of that number which, together with the number itself, is
 * 1-9 pandigital.
 */
bool isOneNineUnusual(int n) {
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
            if (s.length() == 9 && isPandigital(s)) return true;
        }
    }
    return false;
}

/**
 * Find the sum of all products whose factors, concatenated with
 * the product, is 1-9 pandigital.
 * 
 * This of course means that the maximum length of the concatenated
 * string is 9, meaning that a 5-digit number is not possible (since,
 * at minimum, it would require a 3-digit and a 2-digit factor, for
 * a total of 10 digits).
 * 
 * Accordingly, only check up to 9999 (99*101) inclusive.
 * 
 * Additionally, there is no way to arrive at a 9-digit concatenation
 * without the product being 4 digits.  Products of less than 4 digits
 * will have factors of less than 5 digits, concatenated.
 * 
 * Accordingly, only check from 1000 (1000 * 1) inclusive. 
 */
int main() {
    int sum = 0;
    for (int i = 1000; i < 10000; i++) {
        if (isOneNineUnusual(i)) sum += i;
    }
    cout << sum << endl;
    return 0;
}
