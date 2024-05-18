import matplotlib.pyplot as plt
import numpy as np
arr1 = [];
arr2 = [];
arr3 = [];
f = open('fifo_sched.txt', 'r')
f1 = open('rr_sched.txt', 'r')
f2 = open('other_sched.txt', 'r')
for line in f.readlines():
    arr1.append(float(line))
for line in f1.readlines():
    arr2.append(float(line))
for line in f2.readlines():
    arr3.append(float(line))
f.close()
f1.close()
f2.close()

x = np.arange(5);

# prio = [0,17,34,51,68,85]
plt.bar(x - 0.1,arr1, 0.1,color = "red",label = "FIFO")
plt.bar(x,arr2, 0.1,color = "blue",label = "RR")
plt.bar(x + 0.1,arr3, 0.1,color = "green",label = "OTHER")
plt.xticks(x, ('0', '17', '34', '51', '68'))
# plt.bar(arr2, prio[1])
# plt.bar(arr3, prio[2])

plt.legend()
plt.show()

print(arr1)
print(arr2)
print(arr3)
