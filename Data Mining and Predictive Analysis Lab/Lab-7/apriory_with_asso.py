from itertools import combinations
from collections import Counter
data = [
    ['T100', ['I1', 'I2', 'I5']],
    ['T200', ['I2', 'I4']],
    ['T300', ['I2', 'I3']],
    ['T400', ['I1', 'I2', 'I4']],
    ['T500', ['I1', 'I3']],
    ['T600', ['I2', 'I3']],
    ['T700', ['I1', 'I3']],
    ['T800', ['I1', 'I2', 'I3', 'I5']],
    ['T900', ['I1', 'I2', 'I3']]
]

init = []
for i in data:
    for q in i[1]:
        if (q not in init):
            init.append(q)
init = sorted(init)
print(init)

sp = 0.2
min_supp = int(sp*len(init))


c = Counter()
# Storing initial count
for i in init:
    for d in data:
        if (i in d[1]):
            c[i] += 1
print("C1:")
for i in c:
    print(str([i])+": "+str(c[i]))
print()

l = Counter()
for i in c:
    if (c[i] >= min_supp):
        l[frozenset([i])] += c[i]
print("L1:")
for i in l:
    print(str(list(i))+": "+str(l[i]))
print()
pl = l
pos = 1
for count in range(2, 1000):
    nc = set()
    temp = list(l)
    for i in range(0, len(temp)):
        for j in range(i+1, len(temp)):
            t = temp[i].union(temp[j])
            if (len(t) == count):
                nc.add(temp[i].union(temp[j]))
    nc = list(nc)
    c = Counter()
    for i in nc:
        c[i] = 0
        for q in data:
            temp = set(q[1])
            if (i.issubset(temp)):
                c[i] += 1
    print("C"+str(count)+":")
    for i in c:
        print(str(list(i))+": "+str(c[i]))
    print()
    l = Counter()
    for i in c:
        if (c[i] >= min_supp):
            l[i] += c[i]
    print("L"+str(count)+":")
    for i in l:
        print(str(list(i))+": "+str(l[i]))
    print()
    if (len(l) == 0):
        break
    pl = l
    pos = count
print("Result: ")
print("L"+str(pos)+":")
for i in pl:
    print(str(list(i))+": "+str(pl[i]))
print()

for l in pl:
    combination = [frozenset(q) for q in combinations(l, len(l)-1)]
    mmax = 0
    for a in combination:
        b = l-a
        ab = l
        support_ab = 0
        support_a = 0
        support_b = 0
        for q in data:
            temp = set(q[1])
            if (a.issubset(temp)):
                support_a += 1
            if (b.issubset(temp)):
                support_b += 1
            if (ab.issubset(temp)):
                support_ab += 1
        temp = support_ab/support_a*100
        if (temp > mmax):
            mmax = temp
        temp = support_ab/support_b*100
        if (temp > mmax):
            mmax = temp
        print(str(list(a))+" -> "+str(list(b)) +
              " = "+str(support_ab/support_a*100)+"%")
        print(str(list(b))+" -> "+str(list(a)) +
              " = "+str(support_ab/support_b*100)+"%")
    curr = 1
    print("choosing:", end=' ')
    for a in combination:
        b = l-a
        ab = l
        support_ab = 0
        support_a = 0
        support_b = 0
        for q in data:
            temp = set(q[1])
            if (a.issubset(temp)):
                support_a += 1
            if (b.issubset(temp)):
                support_b += 1
            if (ab.issubset(temp)):
                support_ab += 1
        temp = support_ab/support_a*100
        if (temp == mmax):
            print(curr, end=' ')
        curr += 1
        temp = support_ab/support_b*100
        if (temp == mmax):
            print(curr, end=' ')
        curr += 1
    print()
    print()
