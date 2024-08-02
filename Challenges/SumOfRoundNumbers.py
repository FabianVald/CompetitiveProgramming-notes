t = int(input())
numbers = []
for _ in range(t):
    num = int(input())
    numbers.append(num)
 
results = []
for number in numbers:
    lista_numeros = []
    indice = 1
    while number > 0:
        digito = number % 10
        if digito != 0:
            lista_numeros.append(digito * indice)
        number //= 10
        indice *= 10
    results.append(lista_numeros)
 
for result in results:
    print(len(result))
    print(*result)