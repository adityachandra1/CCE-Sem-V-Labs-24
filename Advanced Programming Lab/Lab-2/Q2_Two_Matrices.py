x,y = map(int, input("Enter the order of matrix : ").split())

mat1 = {}
mat2 = {}
mat3 = {}

print("Enter Matrix 1 : ")
for i in range(x):
    row = list(map(int, input().split()))
    for j in range(y):
        mat1[(i,j)] = row[j]

print("Enter Matrix 2 : ")
for i in range(x):
    row = list(map(int, input().split()))
    for j in range(x):
        mat2[(i,j)] = row[j]


for i in range(x):
        for j in range(y):
            mat3[(i,j)] = mat1[(i,j)] + mat2[(i,j)]

print("Dictionary" : mat3);

matrix = [[]]
for elem in mat3:
    elem
    



