#!/usr/bin/python3 

import random

V = 20

start = "E = ["
end = "|];"

print('n = ',V,';')
print(start,end='')
l = 0

for i in range (1,V):
    for j in range (i+1,V+1):
        if random.random() > 0.6:
            print("|",i,",",j,",")
            l += 1

print(end)
print('e = ',l,';')
