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
  int N, M;
  cin >> N >> M;
  vector<int> D(N);
  rep(i, 0, N) cin >> D[i];
  vector<int> C(M);
  rep(i, 0, M) cin >> C[i];

  // DPテーブル定義: 都市iまでにj日間で移動した時の、最小の疲労度
  vector<vector<int> > dp(N+1, vector<int>(M+1));
  
  // DPテーブル初期化
  rep(j, 0, M+1) dp[0][j] = 0; // どの都市にも移動していない時は0
  rep(i, 1, N+1) rep(j, 0, M+1) dp[i][j] = INF; // それ以外の初期値はINF

  // DP漸化式
  rep(i, 0, N) {
    rep(j, 1, M+1) {
      dp[i+1][j] = min((dp[i][j-1] + D[i]*C[j-1]), dp[i+1][j-1]);
    }
  }

  // 出力
  int ans = INF;
  rep(j, 0, M+1) chmin(ans, dp[N][j]);
  cout << ans << endl;
}