# 目次

- [目次](#目次)
- [atcoder abc](#atcoder-abc)
- [1-1. 全探索：全列挙](#1-1-全探索全列挙)
- [1-2. 全探索：工夫して通り数を減らす全列挙](#1-2-全探索工夫して通り数を減らす全列挙)
- [1-3. 全探索：ビット全探索](#1-3-全探索ビット全探索)
- [1-4. 全探索：順列全探索](#1-4-全探索順列全探索)
- [2-1. 二分探索](#2-1-二分探索)
- [2-2. 深さ優先探索](#2-2-深さ優先探索)
- [2-3. 幅優先探索](#2-3-幅優先探索)
- [3-2. 動的計画法：区間 DP](#3-2-動的計画法区間-dp)
- [3-3. 動的計画法：bit DP](#3-3-動的計画法bit-dp)
- [3-4. 動的計画法：その他](#3-4-動的計画法その他)
- [4-1. 最短経路問題：ダイクストラ法](#4-1-最短経路問題ダイクストラ法)
- [5-1. 最小全域木問題](#5-1-最小全域木問題)
- [6-3. 逆元を使う問題](#6-3-逆元を使う問題)
- [6-5. Union-Find](#6-5-union-find)
- [6-6. その他のテクニック](#6-6-その他のテクニック)
- [6-8. 数学的な問題](#6-8-数学的な問題)
- [調べたこと](#調べたこと)

# atcoder abc

[分野別 初中級者が解くべき過去問精選 100 問](https://qiita.com/e869120/items/eb50fdaece12be418faa#2-3-%E5%88%86%E9%87%8E%E5%88%A5%E5%88%9D%E4%B8%AD%E7%B4%9A%E8%80%85%E3%81%8C%E8%A7%A3%E3%81%8F%E3%81%B9%E3%81%8D%E9%81%8E%E5%8E%BB%E5%95%8F%E7%B2%BE%E9%81%B8-100-%E5%95%8F)

# 1-1. 全探索：全列挙

# 1-2. 全探索：工夫して通り数を減らす全列挙

# 1-3. 全探索：ビット全探索

- [ ] おまじない
      行のうち何行か、列のうち何列かを 1 回だけ裏返し、せんべいが 0 になる枚数を求める問題。わからない
- [ ] Buildings are Colorful!
      skip!

# 1-4. 全探索：順列全探索

- [x] C - Average Length
      全ての点を通る経路の、長さの平均値を求める問題。
- [x] C - Count Order
      全探索したい順列を作って、その順列がマッチするか判定すれば ok。
- [ ] 8 クイーン問題
      N クイーン問題で調べると良いかも。prac ファイルの 31 行目以降（どのマス目におけば各クイーンは移動範囲が被らないか？の判定ロジックの部分）がわかってない。next_permutation の使い方はわかったので先に進む。

# 2-1. 二分探索

- [x] 4_B - 二分探索
      binary_search で true を返したらカウントをインクリメントして数えた。以前なら map で問いてたな。
- [x] JOI 2009 本選 2 - ピザ
      lower_bound で宅配先から近い店舗を探す。店舗の配列の先頭だけでなく、末尾にも本店を追加することで、アルゴリズムが簡単になる。19 行目が肝。
- [ ] AtCoder Beginner Contest 077 C - Snuke Festival
      下の段より上の段のパーツが真に小さいパーツでできる祭壇が、何種類あるかを求める問題。下段を全探索したせいで、中段も一部全探索することになる。計算量が O(N^2(logN)^2)（？）になってしまった。中段を全探索することで、下段・上段は二部探索するのみで済み、計算量が O(NlogN)に。
- [ ] AtCoder Beginner Contest 023 D - 射撃王
- [ ] AtCoder Regular Contest 054 B - ムーアの法則
- [ ] JOI 2008 本選 3 - ダーツ

# 2-2. 深さ優先探索

# 2-3. 幅優先探索

# 3-1. 動的計画法：ナップザック DP

# 3-2. 動的計画法：区間 DP

# 3-3. 動的計画法：bit DP

# 3-4. 動的計画法：その他

# 4-1. 最短経路問題：ダイクストラ法

# 4-2. 最短経路問題：ワーシャルフロイド法

# 5-1. 最小全域木問題

# 6-1. 高速な素数判定法

# 6-2. 高速なべき乗計算

# 6-3. 逆元を使う問題

# 6-4. 累積和

# 6-5. Union-Find

# 6-6. その他のテクニック

# 6-7. 実装問題

# 6-8. 数学的な問題

# 調べたこと

- ios::sync_with_stdio(false);
- cin.tie(0);

書かない -> cin を実行した時点で buffering されていた cout が出力(flush)される

書く -> cin を実行しても flush されない

<details>
<summary>コード例</summary>

    int main(void)
    {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

        int n;
        for(int rep = 0; rep < 3; ++rep) {
            std::cout << "Input number: ";
            std::cin >> n;
            std::cout << n << " is given." << std::endl;
        }

        return 0;

    }

</details>

<details>
<summary>実行例</summary>

    100
    Input number: 100 is given.
    200
    Input number: 200 is given.
    300
    Input number: 300 is given.

</details>

────────────────────────────────────────

- \_\_builtin_popcount

1 が何本立っているかを返す

```
__builtin_popcount(7) -> 3
__builtin_popcount(8) -> 1

```
