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

// TLE解答: 下段を全探索したせいで、中段も一部全探索することになる。計算量がO(N^2(logN)^2)に...)
void _main() {
  int N;
  cin >> N;

  vector<int> A(N), B(N), C(N);
  rep(i, 0, N) cin >> A[i];
  rep(i, 0, N) cin >> B[i];
  rep(i, 0, N) cin >> C[i];

  // 忘れない！
  sort(all(A));
  sort(all(B));
  sort(all(C));

  int cnt = 0;

  // 土台から決めていく。Cのある値を選んだ時、条件を満たすB、Aの通りがどれだけあるか探索する
  rep(i, 0, N) {
    // b_idx: Bの配列でC[i]以下の値の数
    auto b_itr = lower_bound(all(B), C[i]);
    int b_idx = b_itr - B.begin();
    
    if (!b_idx) continue;

    // Bのある値を選んだ時、条件を満たすAの通りがどれだけあるか探索する
    rep(j, 0, b_idx) {
      auto a_itr = lower_bound(all(A), B[j]);
      int a_idx = a_itr - A.begin();

      cnt += a_idx;
    }
  }

  cout << cnt << endl;
}
