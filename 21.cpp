#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }

const long long INF = 1LL << 60; //十分大きい値を一つ決める
// ----------------------------------------------------------
void _main() {
  // 入力
  int N;
  cin >> N;
  vector<long long> h(N), s(N);
  rep(i, 0, N) cin >> h[i] >> s[i];

  //二部探索
  long long left = 0, right = INF;
  while ( right - left > 1 ) {
    long long mid = (right + left) / 2; // ペナルティの最大値がmid以下になるかを判定していく

    //判定
    bool ok = true;
    vector<long long> t(N, 0); //各風船を割るまでの制限時間
    rep(i, 0, N) {
      if (mid < h[i]) ok = false; //midが初期高度より低かったらペナルティがmid以上になるので、判定結果はfalse
      else t[i] = (mid - h[i]) / s[i]; // ペナルティがmidを超えるまでに残されている時間
    }

    //時間制限が差し迫っている順にソート
    sort(all(t));
    rep(i, 0, N) {
      if (t[i] < i) ok = false; //時間切れ発生
    }

    if (ok) right = mid; // 時間に余裕があるので mid を 減らす
    else left = mid; // 時間切れしてる(midが厳しすぎる)ので mid を増やす
  }
  
  cout << right <<endl;
}