t = int(input())
 
resultados = []
 
for _ in range(t):
    n_dulces, queries_cantidad = map(int, input().split())
    azucares = list(map(int, input().split()))
    azucares.sort(reverse=True)
    
    suma_acumulada = [0] * n_dulces
    suma_acumulada[0] = azucares[0]
    
    for i in range(1, n_dulces):
        suma_acumulada[i] = suma_acumulada[i-1] + azucares[i]
    
    for _ in range(queries_cantidad):
        quiero_consumir = int(input())
        
        if suma_acumulada[-1] < quiero_consumir:
            resultados.append("-1")
        else:
            # Búsqueda lineal para encontrar el índice
            left, right = 0, n_dulces - 1
            while left < right:
                mid = (left + right) // 2
                if suma_acumulada[mid] >= quiero_consumir:
                    right = mid
                else:
                    left = mid + 1
            resultados.append(str(left + 1))
 
print("\n".join(resultados))