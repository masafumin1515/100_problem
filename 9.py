import numpy as np

m = int(input())
m_list = [np.array(list(map(int, input().split()))) for _ in range(m)]
n = int(input())
n_list = [np.array(list(map(int, input().split()))) for _ in range(n)]
n_dict = { "{}_{}".format(list[0],list[1]): True for list in n_list }

s = m_list.pop(0)

for p in n_list:
    x_diff, y_diff = p - s
    m_dict = { "{}_{}".format(list[0]+x_diff,list[1]+y_diff): True for list in m_list }
    for key in list(m_dict.keys()):
        if not n_dict.get(key):
            break
    else:
        print(x_diff, y_diff)
        break

#  mの一点を特別扱い(s)
# s点をn回平行移動
# for p in list_n
#     差 = sとpの差を求める
#     s以外の点を差分だけ平行移動
#     for t in list_m_shifted
#         if tがlist_nにない
#             break
#     else
#         print(差)
#         break