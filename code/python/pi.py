amount = input('iteration amount: ')
amount = int(amount)

mult = 1
result = float(0)
for i in range(amount):
    fraction = 1/mult
    print(fraction)
    if i % 2 == 0:
        
        result += fraction
    else:
        result -= fraction
    mult += 2

print(f'finished\nresult: {result}\npi: {result * 4}')