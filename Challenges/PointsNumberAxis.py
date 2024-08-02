n = int(input())
x = list(map(int, input().split()))

MOD = 998244353

def ma_c_d(a, b):
    if a == 0:
        return b, 0, 1
    gcd, x1, y1 = ma_c_d(b % a, a)
    x = y1 - (b // a) * x1
    y = x1
    return gcd, x, y

def mod_inv(a, mod):
    gcd, x, _ = ma_c_d(a, mod)
    return x % mod

def res(n, x):
    sum_points = sum(x) % MOD
    inv_n = mod_inv(n, MOD)
    result = (sum_points * inv_n) % MOD
    return result

print(res(n, x))
