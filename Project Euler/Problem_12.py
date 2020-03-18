#Euler Project
#Problem 12

import time
from math import sqrt
start = time.time()

nxt = 1
i = 2
mysqrt = 0
numDivisors = 0

while (numDivisors < 500):
        nxt = nxt + i
        i +=1 
        numDivisors = 0
        mysqrt = int( sqrt(nxt) )

        print (nxt,mysqrt)
        for j in range ( 1, mysqrt ):
                if nxt%j == 0:
                        numDivisors +=2

print (nxt)

end = time.time()
print (end - start)
