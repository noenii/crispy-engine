#try/except...
#check if code will throw an error or not

try:
    print(10/0)
except:
    print('error')

#try... run a block of code
#except... run if it throws an error

#full form is:

try:
    print(10/0)
except:
    print('error')
else:   #will run if there is no error
    print('no error')
finally:    #will run whether theres an error or not
    print('done')

#also will catch specific errors:

try:
    print(10/0)
except ZeroDivisionError:
    print('cant divide by zero')

#you can also create custom exceptions