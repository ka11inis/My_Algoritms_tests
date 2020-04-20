#Euler Project
#Problem 01

import time
start = time.time()

a=0
for i in range(1,1000):
    if (i%5 ==0 or i%3==0):
        a=a+i
print (a)


end = time.time()
print (end - start)