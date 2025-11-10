import random
import string

def ask(question, type):
    while True:
        if type:
            number = input(question)
            if number.isdigit():
                number = int(number)
                return number
            else:
                print('invalid input')
        else:
            q1 = input(question).lower()
            if q1 == 'y':
                return q1
            elif q1 == 'n':
                q1 = False
                return q1
            else:
                print('invalid')

def gen(min_len, num=True, special=True):
    letters = string.ascii_letters
    numbers = string.digits
    spec = string.punctuation

    char = letters

    if num:
        char += numbers
    if special:
        char += spec
    
    generated = ""
    
    while len(generated) != min_len:
        generated += random.choice(char)
    
    return generated

x = ask('how long? ', True)
y = ask('contain numbers? (y/n): ', False)
z = ask('contain special characters? (y/n): ', False)

while True:
    password = gen(x, y, z)

    print(password)

    another = ask('another? (y/n): ', False)
    if another:
        continue
    else:
        break