a,b,c= (map(int, input().split())) #costo, ganancia mensual, cantidad de edificios
 
cantidad_edificios = 1
suma_dolares = 0
mes = 0
 
while cantidad_edificios<c :
    suma_dolares+=cantidad_edificios*b
    cantidad = suma_dolares//a
    suma_dolares = suma_dolares%a
    cantidad_edificios+=cantidad
    mes+=1
 
print(mes)