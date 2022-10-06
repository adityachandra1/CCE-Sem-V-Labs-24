fo = open('file.txt', 'r')
lines = fo.readlines()
lines_cnt, words_cnt, chars_cnt = len(lines), 0, 0
for line in lines:
	words = line.split()
	for word in words:
		words_cnt = words_cnt + 1
		chars_cnt = chars_cnt + len(word)

print(f'No of lines: {lines_cnt}')
print(f'No of words: {words_cnt}')
print(f'No of chars: {chars_cnt}')
fo.close()
