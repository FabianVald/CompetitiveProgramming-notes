n, m = map(int, input().split())
s, t = map(int, input().split())
 
grafo = [[] for _ in range(n + 1)]
for _ in range(m):
    u, v = map(int, input().split())
    grafo[u].append(v)
    grafo[v].append(u)
 
color = [-1] * (n + 1)
lista = [s]
color[s] = 0  
frente = 0
b = True
while frente < len(lista) and b:
    nodo = lista[frente]
    frente += 1
    color_aux = color[nodo]
    for veci in grafo[nodo]:
        if color[veci] == -1:  
            color[veci] = 1 - color_aux
            lista.append(veci)
        elif color[veci] == color_aux:
            b = False
            break
 
if b and color[s] == color[t]:
    print("Yes")
else:
    print("No")