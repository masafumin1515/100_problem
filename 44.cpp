#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int INF = INT_MAX / 2; const ll INFL = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

void _main() {
  int A;
  while(cin >> A){
    if(!A) break;

    // 扱う正四面体数を作成する
    int N_all=0; // 要素数
    vector<int> all(200); // 正四面体数
    rep(i, 1, INF) { 
      int x = i * (i+1) * (i+2) / 6;
      if (x > A) break;

      all[i-1] = x;
      ++N_all;
    }

    // DPテーブル: i番目までの正四面体数からいくつかを選んで、総和をjとする方法を考えた時、選んだ正四面体の個数の最小値
    vector<vector<int> > dp_all(N_all+1, vector<int>(A+1));

    // DPテーブル初期化
    rep(i, 0, N_all+1) rep(j, 0, A+1) dp_all[i][j] = INF; // 最小値問題なのでINF
    dp_all[0][0] = 0;

    // DP漸化式
    rep(i, 0, N_all) {
      rep(j, 0, A+1) {
        if (j-all[i] >= 0) dp_all[i+1][j] = min((dp_all[i][j-all[i]] + 1), (dp_all[i+1][j-all[i]] + 1));
        dp_all[i+1][j] = min(dp_all[i][j], dp_all[i+1][j]);
      }
    }

    // 奇数の正四面体に対して同じ処理
    int N_odd=0;
    rep(i, 0, N_all) if((i % 4) == 0) ++N_odd;
    vector<int> odd(50); // 奇数の正四面体数の配列
    rep(i, 0, N_odd) { 
      if (i*4 >= N_all) break;
      odd[i] = all[i*4];
    }
    vector<vector<int> > dp_odd(N_odd+1, vector<int>(A+1));
    rep(i, 0, N_odd+1) rep(j, 0, A+1) dp_odd[i][j] = INF; 
    dp_odd[0][0] = 0;
    rep(i, 0, N_odd) {
      rep(j, 0, A+1) {
        if (j-odd[i] >= 0) dp_odd[i+1][j] = min((dp_odd[i][j-odd[i]] + 1), (dp_odd[i+1][j-odd[i]] + 1));
        dp_odd[i+1][j] = min(dp_odd[i][j], dp_odd[i+1][j]);
      }
    }

    // 出力
    cout << dp_all[N_all][A] << ' ' << dp_odd[N_odd][A] << endl;
  }
}