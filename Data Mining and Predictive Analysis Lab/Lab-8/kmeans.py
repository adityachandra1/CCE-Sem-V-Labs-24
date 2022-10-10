import itertools
import copy
import csv
import random
import math
records = []
row_count = sum(1 for row in csv.reader( open('kmeans_data.csv') ) )
with open('kmeans_data.csv', 'rt') as f:
    reader = csv.reader(f)
    records=list(reader)
n=len(records[0])
for i in range(0,row_count):
	for j in range(0,n):
		records[i][j]=float(records[i][j])
k=int(input("Enter k: "))
c=[]
for i in range(0,k):
	c.append(random.randint(1,row_count)-1)
flag=0
clusters=[]
for i in c:
	s=set()
	s.add(i)
	clusters.append(s)
for i in range(0,row_count):
	if i not in c:
		sum=0
		min=999
		min_index=0
		for x in range(0,k):
			sum=0
			for j in range(0,n):
				p=records[i][j]-records[c[x]][j]
				sum+=(p*p)
			if min>math.sqrt(sum):
				min=math.sqrt(sum)
				min_index=x
		clusters[min_index].add(i)
while not flag:
	flag=1
	means=[]
	c=[]
	for i in range(0,k):
		s=clusters[i]
		temp=[]
		for x in range(0,n):
			sum=0
			for j in s:
				sum+=records[j][x]
			sum=sum/len(s)
			temp.append(sum)
		c.append(temp)
	for i in range(0,row_count):
		sum=0
		min=999
		min_index=0
		for x in range(0,k):
			sum=0
			for j in range(0,n):
				p=records[i][j]-c[x][j]
				sum+=(p*p)
			if min>math.sqrt(sum):
				min=math.sqrt(sum)
				min_index=x
		if i not in clusters[min_index]:
			flag=0
			for j in range(0,k):
				if i in clusters[j]:
					clusters[j].remove(i)
			clusters[min_index].add(i)
print("The clusters are: ")
print(clusters)
		
	
	