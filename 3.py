str_arr = list(input())

length = 0
count = 0

target_str = list('AGCT')

for s in str_arr:
    if s in target_str:
      count += 1
    else:
      count = 0
    length = max(length, count)

print(f"{length}")

