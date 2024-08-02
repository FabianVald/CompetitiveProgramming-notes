n, m = map(int, input().split())
azul = 0
rojo = 0
while 0 > n-m:
    if m % 2 == 0:
        m //= 2
        rojo += 1
    else:
        m += 1
        azul += 1
 
azul += (n - m)
 
print(rojo + azul)