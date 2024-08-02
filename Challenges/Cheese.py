n, w = map(int, input().split())
 
quesos = []
for i in range(n):
    a, b = map(int, input().split())
    quesos.append((a, b))
 
quesos.sort(key=lambda x: x[0], reverse=True)
 
delicia = 0
for i, j in quesos:
    if w == 0:
        break
 
    if j <= w:
        delicia += i * j
        w -= j
    else:
        delicia += i * w
        w = 0
 
print(delicia)