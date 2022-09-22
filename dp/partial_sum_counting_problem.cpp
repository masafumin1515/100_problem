#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MOD = 1000000009;

// 入力
int n, A;
int a[110];

// DPテーブル
int dp[110][10010];

int main() {
  cin >> n >> A;
  for (int i = 0; i < n; ++i) cin >> a[i];

  // 配列を0埋めする手法: dp の先頭から 0 バイト進めた位置に、0 を sizeof(dp) バイト書き込む
  memset(dp, 0, sizeof(dp));   // 一旦すべて 0 に
  dp[0][0] = 1;                // dp[0][0] だけ 1 に

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= A; ++j) {
      (dp[i+1][j] += dp[i][j]) %= MOD;
      if (j >= a[i]) (dp[i+1][j] += dp[i][j-a[i]]) %= MOD;
    }
  }

  cout << dp[n][A] << endl;
}