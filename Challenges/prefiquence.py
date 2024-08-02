
t = int(input())  
results = []
for _ in range(t):
    n, m = map(int, input().split())  
    a = str(input())
    b = str(input())
    i = 0 
    j = 0  
    largo_maximo = 0
    while i < n and j < m:
        if a[i] == b[j]:
            largo_maximo = i + 1 
            i += 1
        j += 1
    results.append(largo_maximo)
for result in results:
    print(result)