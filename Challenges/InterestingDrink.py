n = int(input())
precios = list(map(int, input().split()))
precios.sort() 
a = int(input())
gastar = []
for i in range(a):
    gastar.append(int(input()))
for cantidad_monedas_dia in gastar:
    l, r = 0, n
    while l < r:
        mitad = (l + r) // 2
        if precios[mitad] <= cantidad_monedas_dia:
            l = mitad + 1
        else:
            r = mitad
    print(l)