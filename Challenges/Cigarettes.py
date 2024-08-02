
n, k = map(int, input().split())
 
fumados = n
colillas = n
 
while colillas >= k:
    new_cigarettes = colillas // k
    fumados += new_cigarettes
    colillas = (colillas % k) + new_cigarettes
 
print(fumados)