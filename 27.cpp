#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }

int m, n, cnt, ans, _x, _y, d[99][99];
int dx[4]={0, -1, 0, 1}, dy[4]={1, 0, -1, 0};
// --------------------------------------------
void dfs(int x, int y){
  if (0>x || x>=n || 0>y || y>=m || d[x][y]==0) return;
  // ↓でdfsを呼ぶ際には氷を割っておかなければならない
  d[x][y] = 0;
  cnt++;
  ans=max(ans, cnt);
  rep(i, 0, 4) if(d[_x=x+dx[i]][_y=y+dy[i]]) dfs(_x, _y);

  // _mainから、dfsの開始地点は全ての区画で実行されるので、割った氷を元に戻しておく。cntも元にもどす。
  d[x][y]=1;
	cnt--;
}

void _main() {
  cin >> m >> n;

  rep(i, 0, n) rep(j, 0, m) cin >> d[i][j];
  rep(i, 0, n) rep(j, 0, m) dfs(i, j);

  cout << ans << endl;
}