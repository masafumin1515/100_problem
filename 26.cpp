#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }

int N,Q;
long long score[200005];
vector<int> v[200005];
// --------------------------------------------
void dfs(int v_1,int v_0){
  if (!v_1) return;

  score[v_1] += score[v_0];
  for(int i:v[v_1]) if (i != v_0) dfs(i, v_1);
}

void _main() {
  cin >> N >> Q;

  rep(i, 0, N-1) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a); // これの意味はわからなかった。
  }

  rep(i, 0, Q) {
    int p, x;
    cin >> p >> x;
    score[p] += x;
  }

  dfs(1, 0); // 頂点(1, 0)でdfsを開始する。score[0]は0。

  rep(i, 1, N+1) cout << score[i] << ' ';
  cout << endl;
}