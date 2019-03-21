import multiprocessing as mp
def fector(n):
    l = []
    for i in range (1,n):
        if n%i == 0:
            l.append(i)
    return l
def is_complete(n):
    l = fector(n)
    s = 0
    for i in l:
        s += i
    if s == n:
        return s
    else:
        return
def get_complete(m):
    pool = mp.Pool(processes = 8)
    results = [pool.apply_async(is_complete,[i]) for i in range (1,(m+1))]
    output = [p.get() for p in results]
    for i in output:
        if i != None:
            print(i)

get_complete(10000)
