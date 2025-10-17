#tuples
#they are like lists but they cannot be changed after being made

my_location = ("this", "sucks")

try:
    my_location[1] = "sucked"
except:
    print("didnt work")

#dictionaries

x = {"a": "b", "fizz": "buzz", 6:7}
print(x["a"])

x.update({6: "syfm"})
x["interstellar"] = "peak"
'''
print(x)

print(x.pop(2))

del(0)
'''
for key, value in x.items():
    print(key, value)

#you can nest dictionarys