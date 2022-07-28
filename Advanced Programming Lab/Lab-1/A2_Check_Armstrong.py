n = input("Enter Number: ")
armstrong = 0;

for digit in n:
    armstrong += int(digit) ** 4
    
if(armstrong == int(n)):
    print("It's an Armstrong Number!")
else:
    print("Nah!, Not an Armstrong Number!")

