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

int N, P[8], Q[8];
void _main() {
  cin >> N;
  rep(i, 0, N) cin >> P[i];
  rep(i, 0, N) cin >> Q[i]; 

  vector<int> ord;
  rep(i, 0, N) ord.push_back(i + 1); // 0~N-1までの配列

  int a = 0, b = 0;
  int idx = 1;
  do {
    // ord と P, Q の値が等しい時、a,bにidxを代入
    bool ok = true;
    rep(i, 0, N) if (ord[i] != P[i]) ok = false;
    if (ok) a = idx;

    ok = true;
    rep(i, 0, N) if (ord[i] != Q[i]) ok = false;
    if (ok) b = idx;

    idx++;
  } while (next_permutation(all(ord)));

  int ans = abs(a-b);
  cout << ans << endl;
}