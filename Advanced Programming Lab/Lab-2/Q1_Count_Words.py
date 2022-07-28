sentence = input("Enter the sentence : ").split()
print("Total Words: " , len(sentence))
words = {}

for word in sentence:
    words[word] = sentence.count(word)

print("Dictionary : ", words)

total_words = 0

for word in words:
    total_words += words[word]


print("Total words : " , total_words)
