#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
using namespace std;
void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

void _main() {
  // 入力
  int N, W;
  cin >> N >> W;

  vector<int> value(N), weight(N);
  rep(i, 0, N) cin >> value[i] >> weight[i];

  // DPテーブルの定義 dp[i+1][j+1] := i番目までの品物のうちいくつかを選び、重さがjになる組み合わせのうち、価値が最大になる組み合わせの価値
  int dp[110][10010];

  // DPテーブルの初期条件 0番目までの品物を選んだ時の価値はゼロ
  rep(w, 0, W+1) dp[0][w] = 0;

  // DP漸化式 
  rep(i, 0, N) {
    rep(w, 0, W+1) {
      if (w >= weight[i]) dp[i+1][w] = max(dp[i][w-weight[i]] + value[i], dp[i][w]);
      else dp[i+1][w] = dp[i][w];
      // dp[i+1][w] = dp[i][w];
      // if (w >= weight[i]) dp[i+1][w] = max(dp[i][w-weight[i]] + value[i], dp[i][w]);
    }
  }

  // 出力
  cout << dp[N][W] << endl;
}