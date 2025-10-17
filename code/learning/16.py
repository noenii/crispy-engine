from collections import Counter


#some useful tools
#counter for counting instances
this = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 7, 9, 2]
"""
#useful functions from there like:
print(Counter.most_common(this))
#most common
"""
#NO NOT HEAPS!!!

import heapq

heapq.heapify(this)
#by default they are min heaps
print(this)