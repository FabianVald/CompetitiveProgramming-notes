n, t = list(map(int, input().split()))
tiempos = list(map(int, input().split()))
libros_demora = 0
siguiente = 0
cantidad_leer = 0
for i in range(n):
    libros_demora += tiempos[i]
    while libros_demora > t:
        libros_demora -= tiempos[siguiente]
        siguiente += 1
    if i - siguiente + 1 > cantidad_leer:
        cantidad_leer = i - siguiente + 1
print(cantidad_leer)