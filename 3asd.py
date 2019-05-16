#1521
n,k=map(int,input().split())
lst=list(range(1,n+1))
rez=list()
#print(lst)
k-=1
i=0
for j in range(n):
    i+=k
    while i>len(lst)-1:
        i-=len(lst)
    rez.append(lst.pop(i))
    
    
print(*rez)
