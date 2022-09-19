#include <bits/stdc++.h>
using namespace std;

// x の偶奇による
int dx[2][6] = {
    {1, 0, -1, 0, 1, -1},
    {1, 0, -1, 0, 1, -1}
};
int dy[2][6] = {
    {0, 1, 0, -1, -1, -1},
    {0, 1, 0, -1, 1, 1}
};

int main() {
    int W, H;
    cin >> W >> H;
    vector<vector<int>> fi(H+2, vector<int>(W+2, 0)); // H+2の理由はわからなかった...H+1で何故かできない
    for (int x = 1; x <= H; ++x) for (int y = 1; y <= W; ++y) cin >> fi[x][y];

    vector<vector<bool>> seen(H+2, vector<bool>(W+2, false));
    auto rec = [&](auto self, int x, int y) -> void { // 自己再帰するラムダ式
        seen[x][y] = true;
        for (int dir = 0; dir < 6; ++dir) {
            int nx = x + dx[x%2][dir], ny = y + dy[x%2][dir];
            if (nx < 0 || nx >= H+2 || ny < 0 || ny >= W+2) continue;
            if (fi[nx][ny] == 1) continue;
            if (!seen[nx][ny]) self(self, nx, ny);
        }
    };
    rec(rec, 0, 0);
    for (int x = 1; x <= H; ++x) for (int y = 1; y <= W; ++y) if (!seen[x][y]) fi[x][y] = 1;
    int res = 0;
    for (int x = 1; x <= H; ++x) {
        for (int y = 1; y <= W; ++y) {
            if (fi[x][y] == 0) continue;
            for (int dir = 0; dir < 6; ++dir) {
                int nx = x + dx[x%2][dir], ny = y + dy[x%2][dir];
                if (fi[nx][ny] == 0) ++res;
            }
        }
    }
    cout << res << endl;
}