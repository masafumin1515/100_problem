# 答えを全て求めて、答えで全探索する

from itertools import product, combinations


n, m = map(int, input().split())
S = [list(map(int, input().split())) for _ in range(m)]

result = 0
for t in product([1, 0], repeat=n):
    combs = [list(c) for c in combinations([i+1 for i, v in enumerate(t) if v == 1], 2)]
    for c in combs:
        if c in S:
            continue
        else:
            break
    else:
        result = max(result, sum(t))
print(result)