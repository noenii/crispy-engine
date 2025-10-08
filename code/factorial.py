amount = input('calculation amount: ')
amount = int(amount)

def factorial():
    mult = amount
    calc = amount

    while True:
        if mult == 1:
            return calc
        mult -= 1
        calc = calc * mult

calculation = factorial()
print(calculation)