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
  // 入力
  int D, N;
  cin >> D >> N;
  vector<int> T(D+1);
  rep(i, 0, D) cin >> T[i];
  vector<int> A(N), B(N), C(N);
  rep(i, 0, N) cin >> A[i] >> B[i] >> C[i];

  // dpテーブル: i日目に服jを選んだ時,i日目までの派手さの最大値
  vector<vector<int> > dp(D+1, vector<int>(N));
  
  // dpテーブル初期化: 
  // 0日目には服を選ばない（服を0個選ぶ）ので、0 最大値問題なのでそれ以外は-1
  rep(i, 0, N) dp[0][i] = 0, dp[1][i] = C[i];
  rep(i, 2, D+1) rep(j, 0, N) dp[i][j] = -1;

  // DP漸化式
  rep(i, 0, D) { 
    rep(j, 0, N) {
      if (A[j] <= T[i] && T[i] << B[j]) {
        rep(k, 0, N) {
          int x = abs(C[j] - C[k]) + dp[i][j];
          dp[i+1][j] = max(dp[i+1][j], x);
        }
      }
    }
  }

  rep(i, 0, D+1) {
    rep(j, 0, N) {
      cout << dp[i][j] << ' ';
    }
    cout << endl;
  }
  
  // 出力
  // int ans = -1;
  // rep(i, 0, N) ans = max(ans, dp[D][i]);

  // cout << ans << endl;
}