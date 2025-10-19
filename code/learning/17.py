#oop, a pain in the ass

#classes
class person:
    species = 'Homo Sapiens'

    def __init__(self, name, age,):
        self.name = name
        self.age = age

person1 = person("me", 15)

print(person1.name, person1.age, person1.species)

#self is a reference for that current instance (obj)
#i dont understand it but i know how to use it
#__init__ constructs it or smth

person2 = person("haru", 16)

print(person2.name, person2.age, person2.species)