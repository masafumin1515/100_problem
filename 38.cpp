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
  int q;
  cin >> q;

  rep(i, 0, q) {
    string X, Y;
    cin >> X >> Y;

    // DPテーブル定義: dp[i+1][j+1] := Sのi番目(0~i番目、個数ではない)までの文字列と、Tのj番目までの文字列に関する、共通部分文字列の長さ
    int dp[1010][1010];
    memset(dp, 0, sizeof(dp));    // 最大値問題なので、0で初期化

    rep(i, 0, X.size()) {
      rep (j, 0, Y.size()) {
        if (X[i] == Y[j]) dp[i+1][j+1] = dp[i][j] + 1;
        else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
      }
    }

    cout << dp[X.size()][Y.size()] << endl;
  }
}