# pow(x, y, z) は x の y 乗を z で割った余りを返す x**y % z より高速
mod = 10**9+7
print(pow(10, 10, mod))  # 10 の 10 乗を 1000000007 で割った余り

# i 番目のアルファベットを整数 i に変換
# ord()で ascii 的なやつに変換して 97 を引けばいい
# "a" は 0 番目なので 0 になる
print(ord("a") - 97)
# 0

# 1 番目のアルファベットは b なので "b" になる
print(chr(97 + 1))
# b

# 再帰の深さの上限を増やす
import sys
sys.setrecursionlimit(500000)

# 無限大
float("inf")

# 勝手にメモ化
from functools import lru_cache
@lru_cache(maxsize=None)  # メモ化したい関数の前につける
def fib():
    pass

# dictのデフォルト値
from collections import defaultdict
cnt = defaultdict(int)  # int を引数にすると 0 が初期値になる

# 直積
from itertools import product
for t in product([1, 2, 3], ["a", "b"]):
    print(t)
# (1, 'a')
# (1, 'b')
# (2, 'a')
# (2, 'b')
# (3, 'a')
# (3, 'b')

# 直積_2
from itertools import product
for t in product(["a", "b"], repeat=3):
    print("".join(t))
# aaa
# aab
# aba
# abb
# baa
# bab
# bba
# bbb

# 順列
from itertools import permutations
# ["a", "b", "c"] の並べ替えをすべて列挙する
for t in permutations(["a", "b", "c"]):
    print(t)
# ('a', 'b', 'c')
# ('a', 'c', 'b')
# ('b', 'a', 'c')
# ('b', 'c', 'a')
# ('c', 'a', 'b')
# ('c', 'b', 'a')

# 組み合わせ
from itertools import combinations
# ["a", "b", "c"] から 2 つ選ぶ組み合わせをすべて列挙する
for t in combinations(["a", "b", "c"], 2):
    print(t)
# ('a', 'b')
# ('a', 'c')
# ('b', 'c')

# 重複を許す組み合わせ
from itertools import combinations_with_replacement
# ["a", "b", "c"] から重複を許して 2 つ選ぶ組み合わせをすべて列挙する
for t in combinations_with_replacement(["a", "b", "c"], 2):
    print(t)
# ('a', 'a')
# ('a', 'b')
# ('a', 'c')
# ('b', 'b')
# ('b', 'c')
# ('c', 'c')

