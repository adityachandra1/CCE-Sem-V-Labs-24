import math

n = int(input("Enter the number: "))
opt = 1
while opt != 0:
    opt = int(input("Enter\n1. For sine value\n2. For square root\n3. For Log of n\n4.0 to Exit\n"))
    if opt == 1: 
        print("Sine: ", math.sin(math.radians(n)))
    elif opt == 2:
        print("Square Root: ", math.sqrt(n))
    elif opt == 3:
        print("Log: ", math.log(n))
    else:
        exit(0)
