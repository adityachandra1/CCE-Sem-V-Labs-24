class AgeError(Exception):
    pass

class AccnoError(Exception):
    pass

class AcctypeError(Exception):
    pass

class Bank:
    def __init__(self, name, age, accno, acctype, balance):
        self.name = name
        self.age = age
        self.accno = accno
        self.acctype = acctype
        self.balance = balance

    def deposit(self,amount):
        self.balance=self.balance+amount

    def withdraw(self,amount):
        if(self.balance>=amount):
            self.balance=self.balance-amount
        else:
            print("Invalid Balance")

    def display(self):
        print(" name ", self.name, "\n", "acc-no", self.accno, "\n", "age ",
              self.age, "\n", "acc-type ", self.acctype, "\n", "balance ", self.balance)

accounts = []

ch = -1
while ch is not str(5):
    print("\nEnter 0 to create an account")
    print("Enter 1 to deposit to account")
    print("Enter 2 withdraw from account")
    print("Enter 3 to display account details")
    print("Enter 4 to exit the bank application")
    print("Enter your choice: ")
    ch = input()
    if ch == str(0):
        name = str(input("Enter the name: "))
        age = int(input("Enter age: "))
        try:
            if (age < 18 and age > 100):
                raise AgeError
        except AgeError:
            print("Age between 18 to 100")
            exit()
            
        accno = (input("Enter accno: "))
        try:
            if (len(accno) < 5):
                raise AccnoError
        except AccnoError:
            print("Acc no should be more than 5 digits")
            exit()
        acctype = (input("Enter acctype: "))
        try:
            if (acctype != "C" and acctype != "S"):
                raise AcctypeError
        except AcctypeError:
            print("Acc type should be C or S")
            exit()
        balance = int(input("Enter the Balance: "))
        B1 = Bank(name, age, accno, acctype, balance)
        accounts.append(B1);
    if ch == str(1):
        acc_no = int(input("Enter accNo: "))
        amountDep = input("Enter amount to for deposit")
        for acc in accounts: 
            if acc_no == acc.accno:
                acc.deposit(amountDep)
    if ch == str(2):
        acc_no = int(input("Enter accNo: "))
        amountWith = input("Enter amount to withdraw")
        for acc in accounts: 
            if acc_no == acc.accno:
                acc.withdraw(amountWith)
    if ch == str(3):
        acc_no = int(input("Enter accNo: "))
        for acc in accounts:
            if acc_no == acc.accno:
                acc.display()
    if ch == str(4):
        print("Exiting")
        break





