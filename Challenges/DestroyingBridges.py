def min_islands(n, k):
    if k == 0:
        return n
    
    #K<n-1
    if k < n-1:
        return n
    
    if k >= n-1:
        return 1
    #Caso N < k
 
 
    
t = int(input())
 
results = []
for _ in range(t):
    n, k = map(int, input().split())
    results.append(min_islands(n, k))
 
for result in results:
    print(result)