import re 

regex = r'\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Z|a-z]{2,}\b'
fo = open('email.txt', 'r')
lines = fo.readlines()
fo.close()

fo = open('valid-emails.txt', 'w');
for line in lines: 
    if re.match(regex, line):
        fo.write(line)
        print(line)

fo.close()

