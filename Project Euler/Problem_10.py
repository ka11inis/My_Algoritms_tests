#Euler Project
#Problem 10

import time
start = time.time()

def primes_sieve1(limit):
    limitn = limit+1
    primes = dict()
    for i in range(2, limitn): primes[i] = True
    for i in primes:
        factors = range(i,limitn, i)
        for f in factors[1:]:
            primes[f] = False
    return [i for i in primes if primes[i]==True]

print (sum(primes_sieve1(2000000)))

end = time.time()
print (end - start)
