def factorial(n):
    if n == 0 or n == 1:
        return 1
    resultado = 1
    for i in range(2, n + 1):
        resultado *= i
    return resultado

def desarreglo(d):
    if d == 0:
        return 1
    elif d == 1:
        return 0
    desarreglo_prev1 = 0
    desarreglo_prev2 = 1
    for i in range(2, d + 1):
        actual = (i - 1) * (desarreglo_prev1 + desarreglo_prev2)
        desarreglo_prev2 = desarreglo_prev1
        desarreglo_prev1 = actual
    return desarreglo_prev1

def contador(n, k):
    conteo = 0
    for d in range(k + 1):
        comb = 1
        for i in range(d):
            comb *= (n - i)
            comb //= (i + 1)
        
        desarreglos_d = desarreglo(d)
        conteo += comb * desarreglos_d
    return conteo

n, k = map(int, input().split())


print(contador(n, k))






