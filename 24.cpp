#include<bits/stdc++.h>
#define r(i,a,b) for(int i=a;i<b;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }

int n,u,k,v,p = 0;
vector<int> d(101, 0), f(101, 0), flag(101, 0); // d: 頂点の発見時刻 f: 頂点の隣接リストを探索し終えた完了時刻 flag: 頂点uに訪れたかどうか 
vector<vector<int> > a(101, vector<int> (101, 0));
// -----------------------------------------------
void dfs(int u){
	if(!flag[u]){
    flag[u]++; 
    d[u]=++p; // ++p: p + 1 してから代入される 
    r(i,1,n+1) if(a[u][i]) dfs(i); 
    f[u]=++p;
  }
}

void _main(){
	cin>>n;
	r(i,0,n){
    cin>>u>>k;
		r(i,0,k){
      cin>>v;
			a[u][v]++; // 1 or 0: 頂点uから頂点vに枝が伸びているか
		}
	}
  
	r(i,1,n+1) dfs(i);
	r(i,1,n+1) cout << i << ' ' << d[i] << ' ' << f[i]<< endl;
}
