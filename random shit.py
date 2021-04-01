s, n = map(int, input().split())
a = [int(input()) for _ in range(n)]
for i in range(n):
    for j in range(i + 1, n):
        if a[i] > a[j]:
            a[i], a[j] = a[j], a[i]

summ = 0
maxi = 1
for i in range(n):
    if summ + a[i] <= s:
        summ = summ + a[i]
        maxi = i
t = a[maxi]
for i in range(maxi, n):
    if summ - t + a[i] <= s:
        summ = summ - t + a[i]
        t = a[i]

print(maxi + 1, t)