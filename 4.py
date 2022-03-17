N, M = map(int, input().split())
str_list = [list(map(int, input().split())) for _ in range(M)]

dict = {}
group_total = 0
for column_1 in range(M-1):
    for column_2 in range(column_1+1, M):
        for row in range(N):
            score = max(str_list[row][column_1], str_list[row][column_2])
            group_total += score
        dict[f"{column_1}_{column_2}"] = group_total
        group_total = 0

print(max(dict.values()))