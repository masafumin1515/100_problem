#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
using namespace std;
void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int INF = INT_MAX / 2; const ll INFL = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

void _main() {
  int n, m;
  cin >> n >> m;

  int c[30];
  rep(i, 0, m) cin >> c[i];

  // DPテーブル: dp[i+1][j] 0番目~i番目までのコインで値段がj円になる時の、最小の枚数 j円を構成できないときはINFとする
  int dp[30][50010]; 
  // rep(i, 0, m+1) dp[0][i] = 0;
  // rep(i, 1, n+1) rep(j, 0, m+1) dp[i][j] = INF;
  rep(i, 0, m+1) rep(j, 0, n+1) dp[i][j] = INF;
  dp[0][0] = 0;

  rep(i, 0, m) {
    rep(j, 0, n+1) {
      if (j - c[i] >= 0) dp[i+1][j] = min((dp[i+1][j-c[i]] + 1), dp[i][j]); // 複数枚okなので、左からの遷移を考える（単一の場合は左上から）
      else dp[i+1][j] = dp[i][j];
    }
  }

  cout << dp[m][n] << endl;
}