#Euler Project                                                                                                            
#Problem 03

"""
The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?
"""

import time
start = time.time()

maxNumber = 600851475143
i = 2

while i^2  < maxNumber:
    while maxNumber % i == 0: maxNumber /= i
    i += 1

print ( int(maxNumber) )

end = time.time()
print (end - start)
