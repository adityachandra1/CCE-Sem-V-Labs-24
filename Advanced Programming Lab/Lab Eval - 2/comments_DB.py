import sqlite3

conn = sqlite3.connect("test.db")

conn.execute('''CREATE TABLE IF NOT EXISTS DATASET(
                ID INT NOT NULL,
                COMMENT TEXT NOT NULL,
                LABEL TEXT NOT NULL);''')

conn.execute("INSERT INTO DATASET VALUES (?,?,?)", (100, "Bad Product", "Positive"))
conn.execute("INSERT INTO DATASET VALUES (?,?,?)", (101, "Good Product", "Positive"))
conn.execute("INSERT INTO DATASET VALUES (?,?,?)", (102, "Ok Product", "Positive"))
conn.execute("INSERT INTO DATASET VALUES (?,?,?)", (103, "Nice Product", "Positive"))
conn.execute("INSERT INTO DATASET VALUES (?,?,?)", (104, "Worst Product", "Negative"))
conn.execute("INSERT INTO DATASET VALUES (?,?,?)", (105, "Decent Product", "Positive"))

cursor = conn.execute("SELECT * FROM DATASET;")

print("DATASET")
for data in cursor:
    print(data[0], data[1], data[2])

ch = int(input("Enter 1 for positive, 2 for negative, 3 for neutral"))
pos = 0
neg = 0
neu = 0

cursor = conn.execute("SELECT * FROM DATASET;")

if ch == 1:
    print("\nPositive Comments")
    for data in cursor:
        if data[2] == "Positive":
            print(data[0], data[1], data[2])
            pos = pos + 1

    print ("Count: " , pos)

if ch == 2:
    print("\nNegative Comments")
    for data in cursor:
        if data[2] == "Negative":
            print(data[0], data[1], data[2])
            neg = neg +1

    print ("Count: " , neg)

if ch == 3:
    print("\nNeutral Comments")
    for data in cursor:
        if data[2] == "Neutral":
            print(data[0], data[1], data[2])
            neu = neu + 1

    print ("Count: " , neu)






