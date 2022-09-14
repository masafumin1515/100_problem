#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#define all(x) (x).begin(),(x).end()
//#pragma GCC optimize ("-O3")
using namespace std;
void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
typedef long long ll; const int inf = INT_MAX / 2; const ll infl = 1LL << 60;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int N, X[8], Y[8];
void _main() {
  cin >> N;
  rep(i, 0, N) cin >> X[i] >> Y[i]; // i個目の(X, Y)座標

  vector<int> ord;
  rep(i, 0, N) ord.push_back(i); // 0~N-1までの配列

  long double sm = 0;
  // ord に順列が入れ替わり代入されていくループ
  do {
    // ord順に経路計算
    rep(i, 0, N - 1) {
      int a = ord[i];
      int b = ord[i + 1];

      long double dx = X[a] - X[b];
      long double dy = Y[a] - Y[b];

      sm += sqrt(dx * dx + dy * dy);
    }
  } while (next_permutation(all(ord))); // next_permutation は配列またはコンテナクラスの範囲 [first, last) を引数で受け取る

  rep(i, 0, N) sm /= (i + 1);
  printf("%.10Lf\n", sm);
}