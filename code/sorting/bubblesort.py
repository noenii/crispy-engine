import random

unsorted = [random.randint(1, 10) for _ in range(20)]

print(unsorted)

while True:
    swapped = False
    for i in range(len(unsorted)-1):
        if unsorted[i] > unsorted[i+1]:
            unsorted[i], unsorted[i+1] = unsorted[i+1], unsorted[i]
            swapped = True
    if not swapped:
        break

print(unsorted)