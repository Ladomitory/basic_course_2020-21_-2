def mf(a, b):
    ans = 1
    for i in range(b, a + 1):
        ans *= i
    return ans
def C(n, k):
    return mf(n, n - k + 1) // mf(k, 1)
ans = 1
for i in range(3):
    x, y = map(int, input().split())
    x, y = min(x, y), max(x, y)
    ans *= C(x + y - 1, x)
print(ans)