#fibonacci sequence calculator
'''
def calculate(iterations):
    if iterations == 0:
        return 0
    elif iterations == 1:
        return 1
    else:
        return calculate(iterations - 1) + calculate(iterations - 2)
    
print(calculate(100))
'''
#*args to accept an arbitrary number of parameters (unordered)
#**kwargs for the same thing but ordered, eg: function(a=1, b=2, c=3)
def dosmth(*args):
    return sum(args)
print(dosmth(9, 10))
#learning about class stuff but im gonna write about it later