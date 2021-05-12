n = int(input())
xmap = dict()
ymap = dict()

for i in range(n):
    x, y = map(int, input().split())

    if x not in xmap.keys():
        xmap[x] = 1
    else:
        xmap[x] += 1

    if y not in ymap.keys():
        ymap[y] = 1
    else:
        ymap[y] += 1

maxx = max(list(xmap.items()))[1]
maxy = max(list(ymap.items()))[1]
print(max(maxx, maxy))

