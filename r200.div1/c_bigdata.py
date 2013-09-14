import random

p = []
h = []
for i in range(100000):
    p.append(random.randint(1, 10000000000))
    h.append(random.randint(1, 10000000000))

p = list(set(p))
h = list(set(h))
n = len(h)
m = len(p)

print n, ' ', m, '\n'
for hi in h:
    print hi, ' '
print '\n'
for pi in p:
    print pi, ' '

