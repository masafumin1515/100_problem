A, B, C, X, Y = map(int, input().split())

gradient = (C + int((-0.5)*(A+B)))
upper_limit = 2*min(X,Y) if gradient > 0 else 2*max(X,Y)
print(upper_limit)
intersept = (A*X + B*Y)

result = intersept if gradient > 0 else (intersept + gradient*upper_limit)

print(result)