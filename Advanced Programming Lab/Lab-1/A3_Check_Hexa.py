s = input("Enter the hexadecimal number: ")

for char in s:
    if (char >= '0' and char <= '9') or (char >= 'A' and char <= 'F'):
        continue
    else:
        print("Not Hexadecimal")
        break

else :
    print ("Yes, Hexadecimal")
