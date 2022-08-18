class Vehicle:
    def __init__(self):
        owner = input("Enter Owner Name: ")
        id = input("Enter ID")
        manufacturer = input("Enter Manufacturer: ")
        self.owner = owner
        self.id = id
        self.manufacturer = manufacturer
        

class Car(Vehicle):
    def __init__(self):
        super().__init__()
        capacity = enter("Capacity? : ");

vhe = Vehicle()
vhe.showDetails;
        

    
