#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
// ---------------------------------
void _main() {
  // 縦横の大きさ
  int height, width;
  cin >> height >> width;

  // スタート・ゴール
  int sx, sy, gx, gy;
  cin >> sy >> sx;
  cin >> gy >> gx;

  sy--;
  sx--;
  gy--;
  gx--;

  // 盤面
  vector<string> field(height);
  rep(i, 0, height) cin >> field[i];

  // スタートから各セルの最短距離
  vector<vector<int> > dist(height, vector<int>(width, -1)); 
  dist[sy][sx] = 0;

  // 訪問予定のセルを入れるキュー(座標なのでpair)
  queue<pair<int, int> > que;
  que.push(make_pair(sy, sx));

  // 幅優先探索
  while (!que.empty()) {
    pair<int, int> current_pos = que.front(); // キューから先頭頂点を取り出す
    que.pop();
    int y = current_pos.first;
    int x = current_pos.second;

    // 隣接セルを探索
    rep(i, 0, 4) {
      int next_y = y + dy[i];
      int next_x = x + dx[i];

      // 例外
      if (next_x < 0 || next_y >= height || next_y < 0 || next_x >= width) continue; // 場外
      if (field[next_y][next_x] == '#') continue; // 壁

      // 未訪問のセルをpush
      if (dist[next_y][next_x] == -1) {
        que.push(make_pair(next_y, next_x));
        dist[next_y][next_x] = dist[y][x] + 1; // (next_x, next_y) の距離も更新
      }
    }
  }

  // 結果出力
  cout << dist[gy][gx] << endl;
}