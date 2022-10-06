class Book:
    def __init__(self,author,title,price,publisher, copies):
        self.author=author
        self.title=title
        self.price=price
        self.publisher=publisher
        self.copies=copies

    def __del__(self):
        print("deleting object")

    def search_title(self,title):
        if(title==self.title):
            print(self.author,self.title,self.price,"\n")
        else:
            print("Not Present")
            
    def search_author(self,author):
        if(author==self.author):
             print("No of copies available= ",self.copies)
        else:
            print("Not Present")

    def buy_no_of_copies(self,num):
        if(num<=self.copies):
            print("Price of ",num,"copies is",num*self.price,"\n")
        else:
            print("Required Copies not in Stock","\n")


books = []
B1 = Book("Aditya", "Algorithms", 690, "MIT", 69)
B2 = Book("Anurag", "DBMS", 600, "MIT", 9)
B3 = Book("Praveen", "App Development", 420, "MIT", 6)
B4 = Book("Akshay", "UI/UX", 90, "MIT", 60)
B5 = Book("Aniket", "Everything", 1000, "MIT", 90)
B6 = Book("Abhay", "MBA Karo", 100, "MIT", 420)


books.append(B1)
books.append(B2)
books.append(B3)
books.append(B4)
books.append(B5)
books.append(B6)


ch = -1
while ch is not str(4):
    print("\nEnter 0 to search book using title")
    print("Enter 1 to search book using authon's name")
    print("Enter 2 to check for number of copies available")
    print("Enter 3 to exit")
    print("Enter your choice: ")
    
    ch = input()
    if ch == str(0):
        title= input("Enter title: ")
        for book in books:
            book.search_title(title)
    if ch == str(1):
        auth = input("Enter author name: ")
        for book in books:
            book.search_author(auth)
    if ch == str(2):
        n=int(input("Enter the number of copies required"))
        for book in books:
            book.buy_no_of_copies(n)
    if ch == str(3):
        print("Exiting")
        break





    

