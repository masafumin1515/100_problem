import itertools as it

# 綺麗↓
n, A = int(input()), [*map(int, input().split())]

# 数列からいくつか抜き出して構成できる数字の個数は、部分集合の個数と同じ（重複こみだけど） ⇨ O(2^n)
yes_nums = set()
for bools in it.product([True, False], repeat=n):
    yes_nums.add(sum(A[i] for i in range(n) if bools[i]))

_ = input()
# 綺麗↓
for m in map(int, input().split()):
    print("yes" if m in yes_nums else "no")