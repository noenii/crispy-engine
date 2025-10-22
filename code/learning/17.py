#oop, a pain in the ass

#classes
class person:
    species = 'Homo Sapiens'

    def __init__(self, name, age,):
        self.name = name
        self.age = age

#a class is like a blueprint, and the object is the actual building

person1 = person("aki", 15) #this is an object

print(person1.name, person1.age, person1.species)

#self is a reference for that current instance (obj)
#i dont understand it but i know how to use it
#__init__ constructs it or smth

person2 = person("haru", 16)

print(person2.name, person2.age, person2.species)

#inheritance is when classes "inherit" from other classes
#code below does not work
'''
class friendly:
    def __init__(self, relation):
        self.relation = relation

class friend(person, friendly):
    def info(self):
        print(self.name, self.age, self.relation)

friend1 = friend("vib", 17)

print(friend1.relation())
'''
