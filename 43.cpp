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
  int N;
  cin >> N;
  vector<string> S(5);
  rep(i, 0, 5) cin >> S[i];

  // DPテーブル 行: 色の種類, 列: 何行まで塗ったか
  vector<vector<int> > dp(3, vector<int>(N+1));

  // DPテーブル初期値(全て0): 0:青, 1:白, 2:赤
  rep(i, 0, 3) rep(j, 0, N+1) dp[i][j] = 0;

  // DP漸化式
  rep(i, 0, N) {
    int B_0=0, W_1=0, R_2=0;
    rep(j, 0, 5) {
      if (S[j][i] != 'B') ++B_0;
      if (S[j][i] != 'W') ++W_1;
      if (S[j][i] != 'R') ++R_2;
    }
    dp[0][i+1] = min((dp[1][i] + W_1), (dp[2][i] + R_2));
    dp[1][i+1] = min((dp[0][i] + B_0), (dp[2][i] + R_2));
    dp[2][i+1] = min((dp[0][i] + B_0), (dp[1][i] + W_1));
  }

  // 出力
  int ans = INF;
  rep(i, 0, 2) chmin(ans, dp[i][N]);
  cout << ans << endl;
}