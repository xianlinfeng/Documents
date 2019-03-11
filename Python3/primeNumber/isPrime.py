import math
def isPrime(x):
    if x<=3:
        return False
    if(x%6 != 1 and x%6 != 5):
        return False
    div= int(math.sqrt(x))
    for i in range(5,div,6):
        if(x%i == 0 or x%(i+2)==0):
            return False
    
    return True

i = 0
while(True):
    if(isPrime(i)):
        print(i)
    i +=1

