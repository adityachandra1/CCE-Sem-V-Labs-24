def uniqueElements(nums):
    return list(set(nums))

l = list(map(int, input("Enter elements in the list: ").split()))
print("All Unique Elements: ", uniqueElements(l))
