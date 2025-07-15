#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n;
  cin >> n;
  long long c = 1;
  while (n > 0) {
    c <<= min(n, 32LL);
    if (c > 1000000007) c %= 1000000007;
    n -= 32;
  }
  cout << c;
}