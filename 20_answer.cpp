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

typedef long long ll;
int N, A[101010], B[101010], C[101010];

// 下段ではなく、中段を全探索する
void _main() {
    cin >> N;
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, N) cin >> B[i];
    rep(i, 0, N) cin >> C[i];
    sort(A, A + N);
    sort(C, C + N);
 
    ll ans = 0;
    rep(b, 0, N) {
        ll a = lower_bound(A, A + N, B[b]) - A;
        ll c = N - (upper_bound(C, C + N, B[b]) - C);
        ans += a * c;
    }
    cout << ans << endl;
}