import random

CHOICES = ['1', '2', '3', '4', '5']
TURNS = 10
LENGTH = 4

def generate_code():
    chosen = []
    while len(chosen) < LENGTH:
        chosen.append(random.choice(CHOICES))
    return chosen

def ask(question):
        q = input(question)
        if q == 'y':
            return True
        else:
            return False

def start():
    begin = ask('start game? (y/n): ')

    if begin == True:
        code = generate_code()
        return code
    else:
        quit()

def check():
    while True:
        guess = input('guess: ')
        valid = []
        for x in guess:
            if x in(CHOICES):
                valid.append(x)
        if len(valid) != LENGTH:
            print('incorrect amount')
            continue
        else:
            return valid

def main():
    code = start()
    print(f'possible digits: {CHOICES}')
    counter = 0

    while True:
        answer = check()
        print(f'you guessed: {answer}')
        correct = 0
        wrong = 0
        for x in range(LENGTH):
            if answer[x] == code[x]:
                correct += 1
            else:
                wrong += 1
        if correct == LENGTH:
            print(f'you won, code was {code}\nit took {counter + 1} try/tries')
            break
        elif counter == TURNS:
            print(f'you lost, code was {code}')
            break
        else:
            counter += 1
        print(f'correct digits: {correct}, incorrect digits: {wrong}\nyou have {TURNS - counter} guesses left\n')

main()