class SubsetGenerator:

	@staticmethod
	def subsets(li, idx):
		if len(li) == idx:
			return [[]]

		newList = SubsetGenerator.subsets(li, idx+1)
		finalList = []

		for subset in newList:
			finalList.append(subset)

		for subset in newList:
			finalList.append([li[idx]] + subset)

		return finalList

a = list(map(int, input().split()))
ans = SubsetGenerator.subsets(a,0)
print(ans)
