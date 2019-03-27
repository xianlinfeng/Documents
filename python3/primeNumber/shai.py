n = 9999999
prime = [0, 0]


for i in range(2, n + 1):
    prime.append(1)


for i in range(2, n):
    if(prime[i] == 1):
        for j in range(2 * i, n, i):
            prime[j] = 0
        # print(i,end='')
        print(i)
