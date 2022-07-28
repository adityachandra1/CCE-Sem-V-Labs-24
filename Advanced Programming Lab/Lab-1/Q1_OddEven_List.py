#taking input
l1 = [int(l1) for l1 in input("Enter elements in List 1\n").split()]
l2 = [int(l2) for l2 in input("Enter elements in List 2\n").split()]
l3 = []

for elem in l1:
    if elem%2 == 0:
        l3.append(elem)
        
for elem in l2:
    if elem%2 == 1:
        l3.append(elem)

print("List 3: " , l3)

