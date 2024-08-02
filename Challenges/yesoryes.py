t = int(input())
listado = []
for _ in range(t):
    listado.append(input())

for i in listado:
    if i.upper() == "YES":
        print("YES")
    else:
        print("NO")