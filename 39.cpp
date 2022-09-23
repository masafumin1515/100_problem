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
  int n, nums[110];
  cin >> n;
  rep(i, 0, n) cin >> nums[i];

  // dpテーブルの定義
  ll dp[110][30];

  // 初期条件
  rep(i, 0, n-1) rep(j, 0, 21) dp[i][j] = 0;
  dp[0][nums[0]] = 1; // 0番目の穴に "+" or "-" を入れた時が初期値

  // DP漸化式
  rep(i, 0, n-2) {
    rep(j, 0, 21) {
      if (j+nums[i+1] <= 20) dp[i+1][j] += dp[i][j+nums[i+1]];
      if (j-nums[i+1] >= 0) dp[i+1][j] += dp[i][j-nums[i+1]];
    }
  }

  // 出力
  cout << dp[n-2][nums[n-1]] << endl;
}