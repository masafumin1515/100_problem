# N = int(input())
# S = list(input())
# str_len = len(S)

# key_dic = {}
# for i in range(str_len):
#     for j in range(i+1, str_len):
#         for k in range(j+1, str_len):
#             key = S[i] + S[j] + S[k]
#             key_dic[key] = key_dic.get(key, 0) + 1

# result = len(list(key_dic.keys()))

# print(result)


N=int(input())
S=input()
d1=[0]*10
d2=[0]*100
d3=[0]*1000
for s in S:
    n=int(s)
    for i in range(100):
        if d2[i]==1:
            d3[i*10+n]=1
    for i in range(10):
        if d1[i]==1:
            d2[i*10+n]=1
    d1[n]=1
print(sum(d3))