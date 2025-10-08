import random
import time

operators = ["+", "-", "*"]
questions = 2
wrong = 0

def write():
    a = random.choice(operators)
    b = random.randint(0, 10)
    c = random.randint(0, 10)
    return a, b, c

input("ready?")
print("---------------------------")

start = time.time()

for i in range(questions):
    counter = 0
    choice, upper, lower = write()
    while True:
        eq = str(upper) + " " + choice + " " + str(lower)
        q = input("question #" + str(i + 1) + "\n" + eq + ": ")
        answer = eval(eq)
        if q == str(answer):
            break
        if counter == 0:
            wrong += 1
        counter += 1

end = time.time()

total = round(end - start, 2)

print("finished, you took: " + str(total) + " seconds, and got: " + str(questions - wrong) + "/" + str(questions))