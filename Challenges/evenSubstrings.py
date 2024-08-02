n = int(input())
s = input().strip()
 
 
contar = 0
for i in range(n):
    if s[i] in '2468':
        contar += (i + 1)
print(contar)