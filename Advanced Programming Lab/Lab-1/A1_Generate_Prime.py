
n, m = map(int, input("Enter n, m: " ).split())

primes = []

for i in range(n, m+1):
    for j in range (2, i):
        if i % j == 0:
            break
    else: 
        primes.append(i)


print(primes)

