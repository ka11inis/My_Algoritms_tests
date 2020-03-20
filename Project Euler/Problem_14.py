#Euler Project
#Problem 14
#slow, but works

import time
start = time.time()

number = 837799
cnt = 0
max_cnt=0
max_number=0

for number in range(2,1000000):
        
        if max_cnt < cnt: 
                max_cnt = cnt
                max_number = number -1
        cnt = 1

        while number > 1:
                
                cnt = 1 + cnt
                if number == 1:
                        pass
                elif number % 2 == 0:
                        number = number/2
                        #print number
                else:
                        number = 3 * number + 1
                        #print number

print ("count ",max_cnt)
print ("number ",max_number)
end = time.time()
print (end - start)
