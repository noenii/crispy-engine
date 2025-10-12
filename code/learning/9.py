#You can make your own functions too, there are many reasons for doing so such as:
#Reusability, Modularity, Readability, Maintainability

def add(num1=1, num2=1):
    #code that will be executed
    return num1 + num2

print(add(1, 1))

#you can also specify the parameters so order doesnt better
#can also nest functions

#theres also lambda functions which are basically a shorter way to define functions

#functions also call themselves for recursion

#pass is as a placeholder for functions but also loops and classes to prevent errors

#local                      vs                  global
#declared outside functions             declared inside functions

#created when the program starts        created when the function is called
#and destroyed when it ends             and destroyed when it returns

#shared across all functions            not shared, exists only in its function

#can be accessed throught the           can only be accessed in the function
#entire program