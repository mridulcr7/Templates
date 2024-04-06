L = [int(x) for x in input().split(',')]
R = [int(x) for x in input().split(',')]

l = max(len(L), len(R))

for i in range(0, l):
    if i<len(L) and i<len(R):
        print(L[i]+R[i], end='')
    elif i<len(L):
        print(L[i], end='')
    else:
        print(R[i], end='')
    if i!=l-1:
        print(',',end='')
