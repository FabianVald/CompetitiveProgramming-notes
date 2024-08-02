t = int(input())
lista = []
for i in range(t):
    n, m = (map(int, input().split()))
    lista.append([n,m])
lista_=[]
for i in lista:
    if i[0]==i[1]:
        print('AC')
    else:
        print('WA')