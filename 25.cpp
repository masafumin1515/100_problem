#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }

bool d[51][51];
int a,b,s,_x,_y,dx[8]={0,-1,-1,-1,0,1,1,1},dy[8]={1,1,0,-1,-1,-1,0,1};

void bfs(int x,int y){
	if(0>x||x>=b||0>y||y>=a) return; // 早期リターン: 想定外の値が来た時
	d[x][y]=0;
	rep(i,0,8) if(d[_x=x+dx[i]][_y=y+dy[i]]) bfs(_x,_y);
}

void _main(){
	while(cin>>a>>b,a||b){
		s=0;
		rep(i,0,b) rep(j,0,a) cin>>d[i][j];
		rep(i,0,b) rep(j,0,a) if(d[i][j]) bfs(i,j),s++;
		cout<<s<<endl;
	}
}
