import re

regex = r'^[a-z]$|^([a-z]).*\1$'

st = input("Enter String: ")
if(re.search(regex, st)): 
    print("Valid") 
else: 
    print("Invalid")
