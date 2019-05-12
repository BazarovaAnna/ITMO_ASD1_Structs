#1494 monobilyard

n=int(input())
flag=True
stack=list()
ma=0
for i in range(n):
    ball=int(input())
    if ball>ma:
        stack+=list(range(ma+1,ball))
        ma=ball
    else:
        cur=stack.pop(-1)
        if ball!=cur:
            flag=False


if flag:
    print("Not a proof")
else:
    print("Cheater")
