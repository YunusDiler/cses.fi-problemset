#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact = (1LL * fact * i) % MOD;
    }
    return fact;
}

int nthCatalan(int n) {
    int numerator = factorial(2 * n);
    
    int denominator = factorial(n);
    
    denominator = (1LL * denominator * factorial(n + 1)) % MOD;

    int inverse = 1;
    int base = denominator;
    int power = MOD - 2;
    while (power > 0) {
        if (power & 1) {
            inverse = (1LL * inverse * base) % MOD;
        }
        base = (1LL * base * base) % MOD;
        power >>= 1;
    }
    
    return (1LL * numerator * inverse) % MOD;
}

int main() {
    int n;
    cin >> n;
    if (n & 1) cout << 0;
    else cout << nthCatalan(n / 2) << endl;
    return 0;
}
