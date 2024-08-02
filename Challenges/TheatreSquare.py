n, m, a = list(map(int,input().split()))


l_n = (n + a - 1) // a
l_m = (m + a - 1) // a

total_losas = l_n * l_m

print(total_losas)
