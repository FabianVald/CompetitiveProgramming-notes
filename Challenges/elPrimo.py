t = int(input())
 
lista = []
for i in range(t):
    string = input()
    lista.append(string)
 
for string in lista:
    count = 0
    if len(string)>1:
        for i in range(len(string)-1):
            # print(string[i])
            if string[i]=='1':
                count+=1
    if count>=1:
        print('Yes')
    else: 
        print('No')