#include<bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
int main(){
  int k;
  cin>>k;
  int x[k],y[k];
  rep(i,k)cin>>x[i]>>y[i];
    int a[8];
  for(int i=0;i<8;i++)a[i]=i;
  do{
    bool f=1;
    rep(i,k)if(a[x[i]]!=y[i])f=0;
    if(f){
      bool f1=1;
      rep(i,8)rep(j,i)if(i-a[i]==j-a[j]||i+a[i]==j+a[j])f1=0;
      if(f1){
        rep(i,8){
          rep(j,8){
            if(a[i]==j)cout<<"Q";else cout<<".";
          }
          cout<<endl;
        }
      }
    }
  }while(next_permutation(a,a+8));
}