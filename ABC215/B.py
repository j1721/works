import math

n=int(input())
m=int(input())
a = [int(input()) for i in range(n)]


for i in a:
    for j in range(m):
        if math.gcd(j, a)==1:
            print(j)