#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }

double calc(double x, double p) {
  return x + p * pow(2, -x / 1.5);
}

void _main() {
    double p;
    cin >> p;
    
    // 三分探索 ternary search
    // 下に凸な関数に対してただ一つの極値（最小値）を求める
    double lt = 0, rt =1e18;
    while (abs(rt - lt) > 1e-10) {
        double x1 = (2 * lt + rt) / 3;
        double x2 = (2 * rt + lt) / 3;

        double v1 = calc(x1, p);
        double v2 = calc(x2, p);

        if (v1 > v2) lt = x1;
        else rt = x2;
    }
    
    double ans = calc(lt, p);
    // if (lt < 0) ans = calc(0, p); // lt = 0にすることで実際には極値をとる点が負であっても負の値を取ることはない

    cout << setprecision(10) << ans << endl;
}