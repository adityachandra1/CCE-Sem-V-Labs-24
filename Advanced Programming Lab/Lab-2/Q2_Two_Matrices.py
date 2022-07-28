x,y = map(int, input("Enter the order of matrix : ").split())

mat1 = {}
mat2 = {}
mat3 = {}

#input
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

#Adding
for i in range(x):
        for j in range(y):
            mat3[(i,j)] = mat1[(i,j)] + mat2[(i,j)]

print("After Addition, Dictionary: ", mat3)

matrix = [[0]*x]*y
for elem in mat3:
    i = elem[0]
    j = elem[1]
    matrix[i][j] = mat3[(i,j)]

print ("After Addition, Matrix: " , matrix)



