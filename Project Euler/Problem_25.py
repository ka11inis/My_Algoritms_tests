#Euler Project
#Problem 25

import time
start = time.time()

a = []
i=0

while True:
    
    if i == 0:
        a.append(1)
    elif i == 1:
        a.append(1)
    else:
        a.append(a[i-1] + a[i-2])
    if len(str(a[i])) == 1000:
        print (i + 1)
        break
    i = i + 1

end = time.time()
print (end - start)


