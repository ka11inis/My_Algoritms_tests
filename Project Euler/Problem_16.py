#Euler Project
#Problem 16

import time
start = time.time()

a = str(2**1000)
cnt=0
for i in a:
     cnt = int(i) + cnt   

print (cnt)

end = time.time()
print (end - start)
