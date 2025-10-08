import random

game = False
won = 0
lost = 0
draw = 0
turn = 0
matches = 0
result = [[0, 2, 1],[1, 0, 2],[2, 1, 0]]
# rock = 0, paper = 1, scissor = 2, user goes first

try:
    match = int(input("how many games? "))
except ValueError:
    print("invalid input")
    quit()

while matches < match:

    rand = random.randint(0, 2)

    user = input("you play: ")
    hand = 0
    bot = ""

    if user.lower() == "rock":
        hand = 0
    elif user.lower() == "paper":
        hand = 1
    elif user.lower() == "scissor":
        hand = 2
    else:
        print("invalid input")
        quit()

    if rand == 0:
        bot = "rock"
    elif rand == 1:
        bot = "paper"
    else:
        bot = "scissor"

    print("bot plays: " + bot)
    hand = int(hand)

    logic = result[hand][rand]

    if logic == 0:
        print("draw")
        draw += 1
    elif logic == 1:
        print("win")
        won += 1
    else:
        print("lose")
        lost += 1

    matches += 1

if won == lost:
    print("game over\nyou drew, you got", won, "/", lost, "\ndrawn:", draw)
elif won > lost:
    print("game over\nyou won, you got", won, "/", lost, "\ndrawn:", draw)
else:
    print("game over\nyou lost, you got", won, "/", lost, "\ndrawn:", draw)