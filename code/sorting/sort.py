import random

amount = 20
first = [] # unsorted list here
sorted = [0] * amount
for val in first:
    if val != 0:
        sorted[val] += 1
display = []
for index, i in enumerate(sorted):
    if i > 0:
        display.extend([index] * i)
for val in display:
    print(val, " ", end='')