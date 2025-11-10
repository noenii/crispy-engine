import time

def ask(question, type):
    if type == True:
        while True:
            amount = input(question)
            if amount.isdigit():
                amount = int(amount)
                if 0 < amount < 86400:
                    return amount
                else:
                    print('not in range\n')
            else:
                print('invalid input\n')
    else:
        if question.lower() != 'n':
            return True

def main():
    while True:
        number = ask('timer length? ', True)
        print(f'starting timer for {number} second(s)')
        while number != 0:
            print(number)
            number -= 1
            time.sleep(1)
        print('finished')
        question = ask(input('quit? '), False)
        if question == True:
            break

main()