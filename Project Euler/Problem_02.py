
res = [1,1,2]
i=3

while True:
    res.append(res[i-2] + res[i-1])
    if (res[i] > 4000000 ):
        break
    i=i+1
res.pop()
odd_fib = [i for i in res if i&1]
print(sum( odd_fib))
