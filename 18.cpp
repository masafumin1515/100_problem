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
  int n;
  cin >> n;

  vector<int> S(n);
  rep(i, 0, n) cin >> S[i];

  int q;
  cin >> q;

  vector<int> T(q);
  rep(i, 0, q) cin >> T[i];

  int cnt = 0;
  rep(i, 0, q) if (binary_search(all(S), T[i])) cnt++;

  cout << cnt << endl;
}