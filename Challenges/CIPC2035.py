t = int(input())
lista = []
for i in range(t):
    lista.append(int(input()))
 
 
for i in lista:
    if i >= 1900:
        print('Division 1')
    elif i <=1899 and i>= 1600:
        print('Division 2')
    elif i <=1599 and i>= 1400:
        print('Division 3')
    elif i <=1399:
        print('Division 4')