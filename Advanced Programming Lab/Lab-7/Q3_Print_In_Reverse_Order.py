fo = open('file.txt', 'r+', encoding='utf-8')
lines = fo.readlines()
lines.reverse()
fo.truncate(0)
fo.seek(0)
print(lines)
for line in lines:
	words = line.split()
	for word in words:
		fo.write(word+' ')
	fo.write('\n')
fo.close()