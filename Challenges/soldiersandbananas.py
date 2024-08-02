k, n, w = list(map(int,input().split()))

costos = 0
for i in range(1,w+1):
    costos = i*k
    n -= costos    
print(max(0,-1*n))
    





