#from collections import Counter


#some useful tools
#counter for counting instances

'''
this = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 7, 9, 2]


#useful functions from there like:
print(Counter.most_common(this))
#most common

#NO NOT HEAPS!!!

import heapq

heapq.heapify(this)
#by default they are min heaps
print(min_this)

#to convert to max heaps:
max_this = [-n for n in this]
heapq.heapify(max_this)
#i have no idea how to remove the negative sign from every element?
#maybe this but im not sure if this affects the heapq functions

for x, y in enumerate(max_this):
    max_this[x] = abs(y)

print(max_this)


import random

smth = []
for i in range(100):
    smth.append(random.randint(0, 20))

heapq.heapify(smth)

#append
heapq.heappush(smth, 23)
#remove (first)
print(heapq.heappop(smth))
#combine with:
print(heapq.heappushpop(smth, 40))

print(smth)

print(heapq.nlargest(5, smth))
print(heapq.nsmallest(10, smth))
'''

#deque = double ended queue
#has constant time complexity for adding/removing elements from both ends
#very efficient, also acts like a queue and stack

from collections import deque

this = deque([3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 7, 9, 2])

this.append(40) #append

this.appendleft(232) #appendleft appends at the start

this.extend([9, 11, 15]) #extend

this.extendleft([111, 67, 69]) #adds to the beginning (reverse order)

this.remove(3) #returns an error if not found

print(this.pop()) #remove right-most element

print(this.popleft()) #remove left-most element

# this.clear() #clear

print(this[2])

print(this[-1])

print(len(this))

#theres more, but thats normal in all code ig

print(this)