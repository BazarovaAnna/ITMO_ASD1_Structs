#1650
n=int(input())
di=dict()
dic=dict()
class Person:
    def __init__(self, name, city,money):
        self.name=name
        self.city=city
        self.money=money
class City:
    def __init__(city, day, money):
        self.day=day
        self.city=city#make a masssive??
        self.money=money
for i in range(n):
    nam,city,money=input().split()
    money=int(money)
    chel=Person(nam,city,money)
    di[nam]=chel
    
    if city not in dic:
        gor=City(city,0,money)
        dic[city]=gor
    else:
        dic[city].money+=money
    
m,k=map(int,input().split())

for i in range(k):
    day,nam,city=input().split()
    day=int(day)
    
    if city not in dic:
        gor=City(city,day,di[nam].money)
        dic[city]=gor
    else:
        
