#include <bits/stdc++.h>

using namespace std;

int n,x;

int main() {
  int a, b, c;
  int sum = 0;

  for (int i = 0; ; i++) {
    cin >> n >> x;
    if (n == 0 && x == 0) break;

    for (a = 1; a < x / 3; a++) {
      for (b = 1; b < x - 2*a; b++) {
        c = x - a - c;
        if (c == 0) sum++;
      }
    }

    cout << sum << endl;
  }
}