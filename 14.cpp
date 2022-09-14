#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int R, C;
	cin >> R >> C;
	vector<int> a(C, 0); // 要素数 C 値 0 で初期化する
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			int x;
			cin >> x;
			a[j] = (a[j] << 1) + x;
		}
	}

	int ans = 0;
	for (int i = 0; i < (1 << R); i++) { // 全ての行の組み合わせに対して
		int sum = 0;
		for (int j = 0; j < C; j++) {
			int tmp = __builtin_popcount(a[j] ^ i); // 
			sum += max(tmp, R - tmp);
		}
		ans = max(ans, sum);
	}
	cout << ans << endl;
	return 0;
}