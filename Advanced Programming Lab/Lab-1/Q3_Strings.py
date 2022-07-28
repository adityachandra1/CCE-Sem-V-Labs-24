
input_string = input("Enter the list of Strings: (Separated by \', \')\n")

l1 = input_string.split(", ")

odd_length_strings = []
same_first_last = []

for s in l1:
    if len(s) >= 2:
        if s[0] == s[-1]:
            same_first_last.append(s)
    if len(s)%2 == 1:
        odd_length_strings.append(s)

print("Number of strings with same first and last characters : " , len(same_first_last))
print(same_first_last)
print("\nStrings with odd length", odd_length_strings)

    
    
