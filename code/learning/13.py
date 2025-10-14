#lists are very useful things!

my_interests = ['music', 'games', 'computers', 'psychology', 'history', 'astronomy']
my_hobbies = ['piano', 'kirka', 'programming']

print(my_interests)
print(my_hobbies)

a = list('icl ts pmo br syfm')

b = [1] * 10

print(a, b)
print(a[2])

b.append("mixing datatypes")
print(b)

b.insert(10, "put shi between")
print(b)

b.extend([3, 1, 4, 1, 5, 9, 2, 6, 5 , 3, 5, 8, 7, 9, 2])
print(b)

b.clear()
print(b)

del b

a[10:] = ""
print(a)

my_interests.remove("music")
print(my_interests)
my_hobbies.pop(0)
print(my_hobbies)

for interest in my_interests:
    print(interest)

#you can nest lists

c = [x for x in range(1, 101)]
print(c)

#python lists dont store the data,
#they store pointers which point to the actual data (pointers? is this a c reference hmmmmmm)