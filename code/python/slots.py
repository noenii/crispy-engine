import random
import time

DEPOSIT_LOWER, DEPOSIT_UPPER = 100, 10000
LINES = 3
MIN_BET, MAX_BET = 10, 100
SLOTS = ['A', 'B', 'C', 'D', 'E', 'F', 'G']
VALUES = {
    'A' : 20, 
    'B' : 15, 
    'C' : 10, 
    'D' : 8, 
    'E' : 5, 
    'F' : 2, 
    'G' : 0, 
}

deposit = 0
line_amt = 0
chance = []
count = 0

#get deposit
def deposit():
    while True:
        deposit_amount = input('\nhow much do you deposit? (100$ - 1000$)\n')
        if deposit_amount.isdigit():
            deposit_amount = int(deposit_amount)
            if DEPOSIT_LOWER <= deposit_amount <= DEPOSIT_UPPER:
                break
            else:
                print('\ninvalid amount\n')
        else:
            print('\ninvalid input\n')
    return deposit_amount

#get lines
def get_lines():
    while True:
        lines_amt = input('\nhow many lines do you bet on? (1 - 3)\n')
        if lines_amt.isdigit():
            lines_amt = int(lines_amt)
            if 1 <= lines_amt <= LINES:
                break
            else:
                print('\ninvalid amount\n')
        else:
            print('\ninvalid input\n')
    return lines_amt

#get bet amount
def get_bet():
    while True:
        get_bet = input('\nhow much do you bet? (10$ - 100$)\n')
        if get_bet.isdigit():
            get_bet = int(get_bet)
            if MIN_BET <= get_bet <= MAX_BET:
                break
            else:
                print('\ninvalid amount\n')
        else:
            print('\ninvalid input\n')
    print(f'total bet is {get_bet * LINES}')
    return get_bet

#generate slot (one)
def get_slots():
    rand = random.choice(SLOTS)
    return rand

#redundant questions
def ask(text, type):
    question = input(text + ' (y/n): ')
    if question != "y" and type == True:
        print('ok bye')
        quit()
    return question

#generate slots (all)
def generate_slots():
    result = []
    if len(result) == 0:
        for x in range(LINES):
            result.append(get_slots())
    else:
        for x in range(LINES):
            result[x] = get_slots()

    return result

#start
question = input('start program? (y/n): ')
if question != "y":
    print('ok bye')
    quit()
else:
    print('\nstarting...\n')
    time.sleep(2)

depos = deposit()
won = 0

while True:
    if count == 0:
        print('welcome to my gambling simulator')
    else:
        q2 = ask('see score?', True)
        if q2 == 'y':
            print(f'your balance is {depos}, and youve gambled {count} times, and won {won}')

    if count == 0:
        ask('\nplace bet?', True)
    while True:
        if count != 0:
            q = ask('another?', False)
            if q != 'y':
                break
            elif q != 'y' and count != 0:
                quit()
        
        lines = get_lines()

        while True:
            bet = get_bet()
            if (bet * lines) > depos:
                print(f'\ncant bet more than you have, your balance is {depos}')
            else:
                print('placing bet(s)...\n')
                depos -= bet * lines
                break
            
        time.sleep(1)
        print('generating...\n')
        time.sleep(2)

        print('the result is.....................................................\n')
        time.sleep(3)

        result = generate_slots()
        whatchu_get = [0, 0, 0]

        for x in result:
            print(x, ' ', end='')

        for x in range(LINES):
            whatchu_get[x] += VALUES[result[x]]
        print('\n')

        combined = 0
        outer = 0
        duplicates = 0

        for x in result:
            for y in result:
                inner = 0
                if outer == inner:
                    continue
                if x == y:
                    duplicates += 1
                inner += 1
            outer += 1
        
        total = 0

        for x in whatchu_get:
            total += x

        if whatchu_get != 0:
            combined += (total * duplicates)

        print('you win', str(combined) + "$")

        won += combined
        depos += combined
        count += 1
