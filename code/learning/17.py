#oop, a pain in the ass

#classes
class person:
    species = 'Homo Sapiens'

    def __init__(self, name, age,):
        self.name = name
        self.age = age

#a class is like a blueprint, and the object is the actual building

person1 = person("aki", 15) #this is an object

#print(person1.name, person1.age, person1.species)

#self is a reference for that current instance (obj)
#i dont understand it but i know how to use it
#__init__ constructs it or smth

person2 = person("haru", 16)

#print(person2.name, person2.age, person2.species)

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
#theres many types of inheritance, single, multi, multi-level, hierarchical and hybrid
#single is when a child class inherits from a parent class
#multi is when a child class inherits from multiple parent classes 
#multi-level is when a child class inherits from a parent class which also inherits from another class
#hierchical is when multiple child classes inherits from a parent class
#hybrid is a combination of two or more types
'''
class Bone:
    def __init__(self, x, y, z, size):
        self.x = x
        self.y = y
        self.z = z
        self.size = size

bone1 = Bone(1, 2, 3, 20)
print(bone1.x)

class smthElse:
    def smthCool(__x__, __y__):
        return __x__ + __y__
    
class Bone1(Bone, smthElse):
    def give(x, y):
        return x + y

bone2 = Bone1(1, 2, 3, 30)
print(Bone1.smthCool(1, 1))
'''
class employment:
    def __init__(self, type, pay, time, req):
        self.type = type
        self.pay = pay
        self.time = time
        self.req = req
    employed = True

career1 = employment("Cybersecurity", "~250k a year", "40 hours a week?", "knowledge in cs, maybe a cs degree")

print(career1.employed)

class something:
    def somethingElse(x, y):
        return x + y
    
class anotherThing:
    def aThing(x, y):
        return x ** y
    
class inherited(something, anotherThing):
    def combined(x, y, z):
        return anotherThing.aThing(something.somethingElse(x, y), z)

print(inherited.combined(20, 11, 4))