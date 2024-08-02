n = int(input())
 
mar = list(map(int, input().split()))
nac = list(map(int, input().split()))
 
lista = []
 
for nivel in mar[1:len(mar)]:
    if nivel not in lista:
        lista.append(nivel)
for nivel in nac[1:len(nac)]:
    if nivel not in lista:
        lista.append(nivel)
 
if len(lista)==n:
    print('I become the guy.')
else:
    print('Oh, my keyboard!')
