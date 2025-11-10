'''
aset = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 7, 9, 2}

print(aset)

aset.add(14)

print(aset)

aset.update("sippin", "on", "promethezene")

print(aset)

#remove() will give an error if the element is not found
aset.remove(3)

print(aset)

#discard() will not
aset.discard(10)

#pop() will remove a random element
aset.pop()

#clear() clears the whole set
aset.clear()

print(aset)

aset2 = frozenset({3.14159265358792, 1.141, 67, 69})
print(aset2)
#cant change frozensets

import array
#'i' = integer
aray = array.array('i', [3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 7, 9, 2])

#arrays and lists are different, lists can change but not arrays.
#lists can have many datatypes but not arrays

for i in range(len(aray)):
    print(aray[i])

print(aray[1:])

#find element
print(aray.index(2))

try:
    aray[0] = 3.14159265358792
except:
    print('didnt work')

#update element
aray[0] = 4

#count how many instances of smth there is
print(aray.count(9))

aray.extend([9])

print(aray)
'''
#tf is list comprehension
this = [i for i in range(100)]

print(this)

#quicker way of fizzbuzzing
#conditions can be used
#they can be nested