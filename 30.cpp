#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
void _main(); int main() { _main(); }

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
// ---------------------------------
void _main() {
  // 縦横の大きさ・チーズの数
  int h, w, n;
  cin >> h >> w >> n;

  // 区画
  vector<string> field(h+1);
  rep(i, 0, h) cin >> field[i];

  int log = 0;

  // 次の硬さのチーズを探す
  rep(k, 0, n) {
    // スタート・ゴール地点の決定
    int sy, sx, gy, gx;
    rep(i, 0, h) {
      rep(j, 0, w) {
        // スタート
        if(k == 0 && field[i][j] == 'S') sy = i, sx = j;
        if(isdigit(field[i][j]) && int(field[i][j] - '0') == k) sy = i, sx = j;
        // ゴール
        if(int(field[i][j] - '0') == k+1) gy = i, gx = j;
      }
    }

    // スタートから各セルの最短距離
    vector<vector<int> > dist(h, vector<int>(w, -1)); 
    dist[sy][sx] = log;

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
        if (next_x < 0 || next_y >= h || next_y < 0 || next_x >= w) continue; // 場外
        if (field[next_y][next_x] == 'X') continue; // 障害物

        // 未訪問のセルをpush
        if (dist[next_y][next_x] == -1) {
          que.push(make_pair(next_y, next_x));
          dist[next_y][next_x] = dist[y][x] + 1;
        }
      }
    }

    log = dist[gy][gx];
  }


  // 結果出力
  cout << log << endl;
}