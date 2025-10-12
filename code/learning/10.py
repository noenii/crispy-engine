#fibonacci sequence calculator

def calculate(iterations):
    if iterations == 0:
        return 0
    elif iterations == 1:
        return 1
    else:
        return calculate(iterations - 1) + calculate(iterations - 2)
    
print(calculate(100))