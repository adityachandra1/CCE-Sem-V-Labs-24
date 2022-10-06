class valueLessThanZeroError(Exception):
    pass

class aLessThanBError(Exception):
    pass

def add(a, b):
    c=a+b
    return c

def sub(a, b): 
    c=a-b
    return c

def multi(a, b):
    c=a*b
    return c

def divi(a, b):
    c=a/b
    return c    

ch=1
while(ch==1):
       print("1.Addition")
       print("2.Subtraction")
       print("3.Multiplication")
       print("4.Division")
       print("5.Quit Calculator")    
       c=0

       try:
        x=float(input("Enter the Value of A:- "))
        y=float(input("Enter the Value of B:- "))
        if(x < y): 
            raise aLessThanBError
       except ValueError:
         print("not valid input")
         exit()
       except aLessThanBError:
         print("A is Less than B") 
         exit()
       choice=int(input("Enter the choice which you want to perform:- "))
       result=0
       try:
          if choice==1:
           result=add(x,y)
           print("The result is:-",result)
          elif choice==2:
               result=sub(x,y)
               print("The result is:-",result)            
          elif choice==3:
               result=multi(x,y)
               print("The result is:-",result)
          elif choice==4:
               if(y==0):
                  raise ZeroDivisionError
               else:
                   result=divi(x,y)
                   print("The result is:-",result)
          elif (choice==5):
               ch=0
          else:
                print("%d is not valid input. Please enter 1, 2 ,3 ,4 or 5." % choice)
       except ZeroDivisionError:
           print("Division by zero is not allowed!")
           exit()