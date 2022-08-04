#taking input
l1 = list(map(int, input("Enter elements in the list 1: ").split()))
l2 = list(map(int, input("Enter elements in the list 2: ").split()))
l3 = []

for elem in l1:
    if elem%2 == 0:
        l3.append(elem)
        
for elem in l2:
    if elem%2 == 1:
        l3.append(elem)

print("List 3: " , l3)

