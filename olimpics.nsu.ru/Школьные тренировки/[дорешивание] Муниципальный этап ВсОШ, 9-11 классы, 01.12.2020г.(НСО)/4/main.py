N, M = map(int, input().split())
def stre(cons, strs, n):
    k = 0
    for i in range(1, len(cons[n])):
        x = cons[n][i] - 1
        if strs[x] < 0:
            stre(cons, strs, x);
        k = max(strs[x], k)
    k += 1;
    strs[n] = k
cons = [0] * N
strs = [-1] * N
for i in range(N):
    cons[i] = list(map(int, input().split()))
    if cons[i][0] == 0:
        strs[i] = 0
for i in range(N):
    if strs[i] < 0:
        stre(cons, strs, i);
    if strs[i] == M:
        print(i + 1, end=" ")