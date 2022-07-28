
n = int(input("Enter Size of Triangle: "))

curr = 1;
for i in range(n):
    for j in range(i+1):
        print(curr, end = '\t')
        curr+=1
    print('\n')
    
