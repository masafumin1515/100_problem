#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }

int H, W, ans;
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
// --------------------------
void _main() {
  cin >> H >> W;

  // 盤面
  vector<string> field(H);
  rep(i, 0, H) cin >> field[i];

  // スタートから各セルまでの最短距離
  vector<vector<int> > dist(H, vector<int>(W, -1)); 
  dist[0][0] = 0;

  // 訪問予定のセルを入れるキュー
  queue<pair<int, int> > que;
  que.push(make_pair(0, 0));

  while(!que.empty()) {
    pair<int, int> current_pos = que.front(); // キューから先頭頂点を取り出す
    que.pop();
    int y = current_pos.first;
    int x = current_pos.second;

    rep (k, 0, 4) {
      int ny = y + dy[k];
      int nx = x + dx[k];
      
      if (ny<0 || (H-1)<ny || nx<0 || (W-1)<nx) continue;
      if (field[ny][nx] == '#') continue;

      if (dist[ny][nx] == -1) {
        dist[ny][nx] = dist[y][x] + 1;
        que.push(make_pair(ny, nx));
      }
    }
  }

  int white=0;
  rep(i, 0, H) rep(j, 0, W) if(field[i][j] == '.') ++white;


  if (dist[H-1][W-1] == -1) cout << -1 << endl; 
  else cout << white - dist[H-1][W-1] - 1 <<endl; 
}