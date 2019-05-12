#1521
n,k=map(int,input().split())
lst=list(range(1,n+1))
rez=list()
#print(lst)
k-=1
i=0
while len(lst)>0:
    i+=k
    #print("index not fised:"+str(i))
    while i>len(lst)-1:
        i-=len(lst)
    #print("index fised:"+str(i))
    run=lst.pop(i)
    rez.append(run)
    #print(lst)
    #print(rez)
    
    
print(*rez)
#1 2 3 4 5
#2 4 1 5 3

#31524
