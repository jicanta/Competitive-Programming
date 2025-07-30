
n = int(input())
k = int(input())
m = int(input())


if n == 1:
    print((k - 1) % m)
    exit()

def mul(a, b):
    return (
        (a[0] * b[0] + a[1] * b[2]) % m,
        (a[0] * b[1] + a[1] * b[3]) % m,
        (a[2] * b[0] + a[3] * b[2]) % m,
        (a[2] * b[1] + a[3] * b[3]) % m,
    )

M = (0, 1, (k - 1) % m, (k - 1) % m)
res = (1, 0, 0, 1)
e = n - 1
while e:
    if e & 1:
        res = mul(res, M)
    M = mul(M, M)
    e >>= 1

T0 = 1 % m
T1 = (k - 1) % m
ans = (res[2] * T0 + res[3] * T1) % m
print(ans)
