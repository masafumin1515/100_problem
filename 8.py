n = int(input())
list_f = []
list_b = []
for _ in range(n):
    f, b = list(map(int, input().split()))
    list_f.append(f)
    list_b.append(b)

list_f.sort()
list_b.sort()

s = list_f[n // 2]
t = list_b[n // 2]
dist_between_two_points = 0

ans = 0
for a, b in zip(list_f, list_b):
    ans += abs(a - s)
    ans += b - a
    ans += abs(b - t)
print(ans)