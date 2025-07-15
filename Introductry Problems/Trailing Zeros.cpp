#include <bits/stdc++.h>

using namespace std;

int main() {
  long long n, c, a;
  cin >> n;
  c = 0;
  a = n;
  while (n) {
    c += n % 5;
    n /= 5;
  }
  cout << (a - c) / 4;
}