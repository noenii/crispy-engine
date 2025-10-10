import random

unsorted = [random.randint(1, 10) for _ in range(20)]
sorted = []

print(unsorted)

while len(unsorted) != 0:
    smallest = min(unsorted)
    sorted.append(smallest)
    unsorted.remove(smallest)

print(sorted)