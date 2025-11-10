import random

guesses = 0

num = input("range: ")
if num.isdigit():
    num = int(num)
    if num <= 0:
        print("range less than 0")
        quit()

rand = random.randint(1, num)

while True:
    guess = input("guess: ")
    if guess.isdigit():
        guess = int(guess)
        if guess == rand:
            print("correct")
            break
        else:
            if guess > rand:
                print("too high")
            if guess < rand:
                print("too low")
            guesses += 1
            continue

print("number was", rand)
if guesses == 1:
    print("it took", guesses, "try")
else:
    print("it took", guesses, "tries")