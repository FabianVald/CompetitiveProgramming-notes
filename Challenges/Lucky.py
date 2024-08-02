t = int(input())
 
lista = []
for i in range(t):
    lista.append(input())
    
for i in range(len(lista)):
    primeros = lista[i][:3]
    ultimos = lista[i][3:]
    
    suma_primeros = int(primeros[0])+int(primeros[1])+int(primeros[2])
    suma_ultimos = int(ultimos[0])+int(ultimos[1])+int(ultimos[2])
    
    if suma_primeros == suma_ultimos:
        print("YES")
    else:
        print("NO")