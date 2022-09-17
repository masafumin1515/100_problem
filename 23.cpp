#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }

void _main(){
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    rep(i, 0, n) cin >> p[i];
    p.push_back(0); // 0点の領域を追加し常に4本投げると考える

    vector<int> vec;
    rep(i, 0, n + 1){
        rep(j, 0, n + 1){
            vec.push_back(p[i] + p[j]); // 先に2本同時に投げた時の得点がとりうる値
        }
    }

    sort(all(vec));

    int ans = 0;
    
    // 二分探索: (m - x(残りの2本の得点)) で vec を二分探索する
    rep(i, 0, n+1){
        rep(j, 0, n+1){
            int x = p[i] + p[j];
            int flag = m - x;
            if(flag < vec[0]) continue;

            auto it = lower_bound(all(vec), flag);
            int idx = it - vec.begin();
            if(vec[idx] + x > m) idx--;

            ans = max(ans, x + vec[idx]);
        }
    }

    cout << ans << endl;
}