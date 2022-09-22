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
  int n;
  cin >> n;
  
  // DPテーブル
  int dp[50];

  // DPテーブルの初期化・初期条件
  rep(i, 0, n) dp[i] = 0;
  dp[0] = 1;
  dp[1] = 1;

  // 各セルの計算
  rep(i, 2, n+1) dp[i] = dp[i-1] + dp[i-2];

  // 出力
  cout << dp[n] << endl;
}