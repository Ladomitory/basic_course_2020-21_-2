n = int(input())
stars = []
y = []
x = []
yType = []
xType = []
counter = []

for i in range(n):
    stars.append([int(x) for x in input().split()])

for i in range(n):
    X = stars[i][0]
    Y = stars[i][1]
    x.append(X)
    y.append(Y)
    
    if X not in xType:
        xType.append(X)
    if Y not in yType:
        yType.append(Y)

for i in range(len(xType)):
    c = 0
    for j in range(len(x)):
        if xType[i] == x[j]:
            c += 1
    counter.append(c)

for i in range(len(yType)):
    c = 0
    for j in range(len(y)):
        if yType[i] == y[j]:
            c += 1
    counter.append(c)

if n == 2:
    print(2)
else:
    print(max(counter))