#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
using Graph = vector<vector<int> >;

void _main() {
  // 頂点数
  int N; 
  cin >> N;

  // 有向グラフ入力受取
  Graph G(N+1);
  rep (i, 0, N) {
    int v, k;
    cin >> v >> k;
    rep (j, 0, k) {
      int x;
      cin >> x;
      G[v].push_back(x);
    }
  }

  // BFS のためのデータ構造
  vector<int> dist(N+1, -1); // 全頂点を「未訪問」に初期化
  queue<int> que;

  // 初期条件 (頂点 0 を初期ノードとする)
  dist[1] = 0;
  que.push(1); // 0 を橙色頂点（訪問済み）にする

  // BFS 開始 (キューが空になるまで探索を行う)
  while (!que.empty()) {
    int v = que.front(); // キューから先頭頂点を取り出す
    que.pop();

    // v から辿れる頂点をすべて調べる
    for (int nv : G[v]) {
        if (dist[nv] != -1) continue; // すでに発見済みの頂点は探索しない

        // 新たな白色頂点 nv について距離情報を更新してキューに追加する
        dist[nv] = dist[v] + 1;
        que.push(nv); // queにはこれから訪問する頂点を入れていく
    }
  }

  // 結果出力 (各頂点の頂点 0 からの距離を見る)
  rep (i, 1, N+1) cout << i << " " << dist[i] << endl;
}