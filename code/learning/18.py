#polymorphism???
#idk wat ts is
#"same operation, different behavior" ig
class animal:
    def __init__(self, name, type):
        self.name = name
        self.type = type
    
    alive = True

    def sound(self, value):
        print(value)

duck = animal("Duck", "Bird")
duck.sound("quack")

#then overrides speak()
class fish(animal):
    def sound(self):
        print("bubbbbbblll")

salmon = fish("Salmon", "big fishy")
salmon.sound()

#encapsulation is when you restrict data and methods to its parent classes, somewhat useful ig
#there are 3 types: public, protected and private
#public is accessible everywhere, protected only in its class and subclasses, private is only in its class

class staff:
    def __init__(self, role, activity):
        self._role = role   #_ for protected stuff
        self.__activity = activity  #double _ for private stuff

    friend = True

person = staff("mod", "10h/d")

#print(person.activity)     <--     gives an error

#abstraction, what to do instead of how to do it
#ironic innit? smth for making things easier is hard to understand