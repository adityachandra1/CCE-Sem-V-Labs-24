import time
name = input("Enter Name: ")
epoch = int(time.time())
current_time = time.localtime(epoch)
print(f'{current_time.tm_hour}h: {current_time.tm_min}m: {current_time.tm_sec}s')
 
if current_time.tm_hour > 20:
    print("Good Night", name)
elif current_time.tm_hour >16:
    print("Good Evening", name)
elif current_time.tm_hour > 12:
    print("Good Afternoon", name)
else:
    print("Good Morning", name)

#just for fun
if current_time.tm_min % 2 == 0:
    print("Even Minute")
else:
    print("Odd Minute")

if current_time.tm_sec % 2 == 0:
    print("Even Second")
else:
    print("Odd Second")
