while True:
    N,X = map(int,input().split())
    if N == 0 and X == 0:
        break
    ans = 0
    for a in range(1,int(X/3)):
        for b in range(a+1,X):
            c = X-(a+b)
            if c <= b:
              continue
            if c <= N:
                ans += 1
    print("%d"%(ans))
