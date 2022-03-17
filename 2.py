
from sys import stdin
input = stdin.readline
# input().rstrip()

N = int(input())

total_count = 0
for i in range(1, N+1):
    if i % 2 == 0: continue

    divisor_count = 0;
    for j in range(1, i+1):
        if i % j == 0: divisor_count += 1
    
    if divisor_count == 8: total_count += 1

print(f"{total_count}")

