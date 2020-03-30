#Euler Project
#Problem 20

import time
start = time.time()

a=[]
for i in range(1,100+1):
     if i == 1:
          a.append(i)
     a.append(i * a[i-1])

s =  a[100]
cnt =0
for i in str(s).strip():
     cnt = cnt + int(i)
print (cnt)
end = time.time()
print (end - start)


