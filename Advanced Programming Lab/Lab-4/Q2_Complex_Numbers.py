import math
import cmath

i,j = map(int, input("Enter the complex number (i,j): ").split())
n = complex(i,j)
opt = 1
while opt != 0:
    opt = int(input("Enter\n1. For sine value\n2. For square root\n3. For Log of n\n4.0 to Exit\n"))
    if opt == 1: 
        print("Sine: ", cmath.sin(n))
    elif opt == 2:
        print("Square Root: ", cmath.sqrt(n))
    elif opt == 3:
        print("Log: ", cmath.log(n))
    else:
        exit(0)
