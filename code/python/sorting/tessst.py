import random

def generate(amount):
    return [random.randrange(0, amount) for _ in range(amount)]

def sort(amount):
    values = generate(amount)
    sorted = [0] * amount
    for val in values:
        if val != 0:
            sorted[val] += 1
    return sorted

def display(amount):
    sli = sort(amount)
    display = []
    for index, i in enumerate(sli):
        if i > 0:
            display.extend([index] * i)
    return display

def looks(final):
    for val in final:
        print(val, " ", end='')

looks(display(20))