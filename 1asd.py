#1067 disk tree
n=int(input())
s=list()
for i in range(n):
    s.append(list(input().split("\\")))
s.sort()

#for ss in s:
    #print(ss)
i=0
se=set()
li=list()

for ss in s:
    for i in range(len(ss)):
        word=" "*(i)+ss[i]
        root=str(ss[:i])
        
        if root+word not in se:
            se|={root+word}
            li.append(word)
            #print("new node")
    
    
for ss in li:
    print(ss)
