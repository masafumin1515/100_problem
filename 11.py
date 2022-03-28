# 答えを全て求めて、答えで全探索する
from itertools import product

N, M = map(int, input().split())
S = [list(map(int, input().split())) for _ in range(M)]
_ = [s.pop(0) for s in S]
P = [*map(int, input().split())]

sum = 0
for t in product([1, 0], repeat=N):
    for i, s in enumerate(S):
        count = 0
        for num in s:
            count += t[num-1]
        if count % 2 == P[i]:
            continue
        else:
            break
    else:
        sum += 1

print(sum)