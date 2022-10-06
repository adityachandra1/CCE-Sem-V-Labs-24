import sqlite3

class DataItem:
    def __init__(self, ID, comment, label):
        self.ID = ID
        self.comment = comment
        self.label = label

    def print_data(self):
        print(self.ID, self.comment, self.label)


dataset = []

D1 = DataItem(100, "Bad Product", "Negative")
D2 = DataItem(101, "Good Product", "Positive")
D3 = DataItem(102, "Ok Product", "Neutral")
D4 = DataItem(103, "Nice Product", "Positive")
D5 = DataItem(104, "Worst Product", "Negative")
D6 = DataItem(105, "Decent Product", "Positive")

dataset.append(D1)
dataset.append(D2)
dataset.append(D3)
dataset.append(D4)
dataset.append(D5)
dataset.append(D6)

pos = 0
neg = 0
neu = 0

print("DATASET")
for data in dataset:
    print(data.ID, data.comment, data.label)

ch = int(input("Enter 1 for positive, 2 for negative, 3 for neutral"))

if ch == 1:
    print("\nPositive Comments")
    for data in dataset:
        if data.label == "Positive":
            data.print_data()
            pos = pos + 1

    print ("Count: " , pos)

if ch == 2:
    print("\nNegative Comments")
    for data in dataset:
        if data.label == "Negative":
            data.print_data()
            neg = neg + 1

    print ("Count: " , neg)

if ch == 3:
    print("\nNeutral Comments")
    for data in dataset:
        if data.label == "Neutral":
            data.print_data()
            neu = neu + 1

    print ("Count: " , neu)




    
    
