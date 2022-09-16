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

void _main(){
  int k;
  cin>>k;
  int x[k],y[k];

  rep(i,0,k) cin>>x[i]>>y[i];
  
  // a[i]: i行目に置かれているクイーンの列番号
  int a[8];
  rep(i,0,8) a[i]=i;

  // 各行に置かれるクイーンは何列目に置かれるか？全ての列の通りを試す
  do{
    // f == 1: 既にクイーンが置かれた行と列を、aが考慮している
    bool f=1;
    rep(i,0,k) if(a[x[i]]!=y[i]) f=0;

    if(f){
      // f1 == 1: ? どういう判定方法なのかわからない
      bool f1=1;
      rep(i,0,8) { 
        rep(j,0,i) { 
          if(i-a[i]==j-a[j]||i+a[i]==j+a[j]) f1=0; // 
        }
      }

      if(f1){
        rep(i,0,8){
          rep(j,0,8){
            if(a[i]==j) cout<<"Q";else cout<<".";
          }
          cout<<endl;
        }
      }
    }
  }while(next_permutation(a,a+8));
}