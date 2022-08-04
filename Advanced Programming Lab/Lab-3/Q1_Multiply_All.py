def multiplyAll(nums):
    product = 1
    for num in nums:
        product *= num

    return product

l = list(map(int, input("Enter elements in the list: ").split()))

print("Product of all numbers", multiplyAll(l));
