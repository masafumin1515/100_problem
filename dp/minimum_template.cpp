// 無限大の値
const long long INF = 1LL << 60;

// DP テーブル
long long dp[100010];

// DP テーブル全体を初期化 (最小化問題なので INF に初期化)
for (int i = 0; i < 100010; ++i) dp[i] = INF;

// 初期条件
dp[0] = 0;

// ループ
for (int i = 0; i < N; ++i) {
    chmin(dp[なにか], dp[なにか] + なにか);
    ...
}

// 解を得て出力
cout << dp[N-1] << endl;