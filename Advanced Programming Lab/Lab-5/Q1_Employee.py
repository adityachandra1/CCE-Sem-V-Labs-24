class Employee:
	def __init__(self, id, name, salary, department):
		self.emp_details = (id,name,int(salary),department)

def searchList(a, id):
	for index, tup in enumerate(a):
		if tup[0] == id:
			return f'id {id} found. Name: {tup[1]}, Salary: {tup[2]}, Dept: {tup[3]}'
	return f'id {id} not found'

a = []
n = int(input("Enter number of employees: "))

for i in range(n):
    print("Enter id, name, salary, department");
    id, name, salary, department = input().split()
    details_tup = Employee(id,name,salary,department).emp_details
    a.append(details_tup)

print("List: ", a)

id = input("\nEnter id to search: ")
print(searchList(a, id))
