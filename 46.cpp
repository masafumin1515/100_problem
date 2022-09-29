#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;
void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int INF = INT_MAX / 2; const ll INFL = 1LL << 60;

void _main() {
	int p[101], n;
	cin >> n;
	rep(i, 0, n) cin >> p[i] >> p[i+1];

  // DPテーブル
  int dp[101][101];
	rep(i, 1, n+1) dp[i][i]=0;

  // DP漸化式
	rep(l, 2, n+1) {
		rep(i, 1, n-l+2) {
			int j=i+l-1;
			dp[i][j]=INF;
			rep(k, i, j) dp[i][j]=min(dp[i][j], dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j]);
		}
	}

  rep(i, 0, n+1) {
    rep(j, 0, n+1) {
      cout << dp[i][j] << ' ';
    }
    cout << endl;
  }

	cout << dp[1][n] << endl;
}
