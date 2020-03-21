#Euler Project
#Problem 15

import time
start = time.time()

pinakas = 21
myarray = [[0 for x in range(pinakas)] for y in range(pinakas)] 


for i in range(pinakas):
        for j in range(pinakas):
                if (i == 0) or (j == 0):
                        myarray[i][j] = 1
                else:
                        myarray[i][j] = myarray[i-1][j] + myarray[i][j-1] 


print (myarray[pinakas-1][pinakas-1])

end = time.time()
print (end - start)
