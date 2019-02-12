#!/usr/bin/python3 
import subprocess
import os
import  sys
import random


V = 33


'''
This script will generate three data files for the graph coloring problem in MiniZinc
1data.dzn will have 5% more constraints than 0data.dzn
2data.dzn will have 5% more constraint than 1data.dzn

'''


os.chdir('/home/ubuntu/Documents/minizinc/color/data')
# print(os.getcwd())

e = 0 # number of edges

E = [] # set of the edges


for i in range (1,V):
    for j in range (i+1,V+1):
        if random.random() > 0.4:
            edge = "| " + str(i) + ", " + str(j) + ","
            E.append(edge)

start = "E = ["
end = "|]; \n"






''' write  to the first file '''
# the original problem

os.remove('/home/ubuntu/Documents/minizinc/color/data/3data.dzn')
d3 = open('3data.dzn',"x")
str3 = "n = " + str(V) + " ; \ne = " + str(len(E)) + "; \n"+ start
d3.write(str3)
for i in range(0,len(E)):
    str3 = E[i]
    d3.write(str3)
    d3.write(" \n")

d3.write(end)
d3.close()


''' write to the second file '''
# delete 3% edges from the original problem
H = []
for i in range (0,len(E)):
    if random.randint(1,100) > 5:
        H.append(E[i])

os.remove('/home/ubuntu/Documents/minizinc/color/data/2data.dzn')
d2 =open('2data.dzn',"x")
str2 = "n = "+ str(V) + " ; \ne = " + str(len(H)) + "; \n"+ start
d2.write(str2)
for i in range(0,len(H)):
    str2 = H[i]
    d2.write(str2)
    d2.write(" \n")

d2.write(end)
d2.close()



''' write to the third file '''
# delete 5% edges from the original problem
F = []
for i in range (0,len(H)):
    if random.randint(1,100) > 5:
        F.append(H[i])

os.remove('/home/ubuntu/Documents/minizinc/color/data/1data.dzn')
d1 =open('1data.dzn',"x")
str1 = "n = "+ str(V) + " ; \ne = " + str(len(F)) + "; \n"+ start
d1.write(str1)
for i in range(0,len(F)):
    str1 = F[i]
    d1.write(str1)
    d1.write(" \n")

d1.write(end)
d1.close()



''' write to the fourth file'''
# delete 10% constraint to the orignal problem
G = []
for i in range (0,len(F)):
    if random.randint(1,100) > 5:
        G.append(F[i])

os.remove('/home/ubuntu/Documents/minizinc/color/data/0data.dzn')
d0 = open('0data.dzn',"x")
str0 = "n = "+ str(V)+ " ; \ne = " + str(len(G)) + "; \n"+ start
d0.write(str0)
for i in range(0,len(G)):
    str0 = G[i]
    d0.write(str0)
    d0.write(" \n")

d0.write(end)
d0.close()













