fo = open('file.txt', 'r')
lines = fo.readlines()
dic = {}
for line in lines:
	words = line.split()
	for word in words:
		if word not in dic:
			dic[word] = 1
		else:
			dic[word] = dic[word] + 1		

print(dic)
fo.close()
