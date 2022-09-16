#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std;
void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

void _main() {
  int d, n, m;
  cin >> d >> n >> m;

  vector<int> stores(n+1, 0);
  rep (i, 1, n) cin >> stores.at(i);
  stores.push_back(d);

  vector<int> address(m, 0);
  rep (i, 0, m) cin >> address.at(i);

  sort(all(stores));
  // sort(all(address)); 2分探索される配列ではないのでソートの必要なし

  int sum = 0;
  rep (i, 0, m) {
    int distance = 0;
    auto itr = lower_bound(all(stores), address[i]);
    int idx = itr - stores.begin();

    if (idx == 0) {
      // distance が 0
      continue;
    } else {
      distance = min(abs(stores[idx] - address[i]), abs(stores[idx - 1] - address[i]));
      sum += distance;
    }
  }

  cout << sum << endl;
}