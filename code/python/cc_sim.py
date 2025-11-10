import random
import time

print("welcome to the 100%% accurate chess.com simulator :)\n")
print("this is incomplete cus i gave up, so warning there are bugs, unintentional or not ;)")

try:
    name = input("choose your user: ")
    elo = int(input("whats your elo: "))
except ValueError:
    print("invalid")
    quit()

game_result = 0
description = ""

def ban(reason):
    print("you have been banned for", reason)

def elo_result(x):
    if x >= 2000:
        return 1
    elif 1500 < x < 2000:
        return 2
    else:
        return 3

bot = input("are you human? (y/n): ")
if bot == "y":
    pass
elif bot == "n":
    ban("spam")
    quit()
else:
    print("invalid")
    quit()

print("welcome to chess.com!")

while True:
    menu = input("MENU | [play] , [profile] , [puzzles] , [socials] , [support] , [messages] | inputs = (1) , (2) , (3) , (4) , (5) , (6)\n")

    if menu == "1":
        playing = input("start game? (y/n): ")
        if playing == "y":
            while True:
                if playing == "y":
                    fair_play = random.randint(elo_result(elo), 10)
                    if fair_play == 2:
                        print(ban("violating our fair play policy"))
                        quit()
                    match = random.randint(elo_result(elo), 2)
                    if match == 1:
                        print("lose")
                        elo -= 10
                        print("your elo is now", elo)
                    else:
                        print("win")
                        elo += (elo_result(elo) * 3)
                        print("your elo is now", elo)
                    rematch = input("another game? (y/n): ")
                    if rematch == "y":
                        continue
                    elif rematch == "n":
                        break
                    else:
                        print("invalid")
                        break
                elif playing == "n":
                    break
                else:
                    print("invalid")
        elif playing == "n":
            break
        else:
            print("invalid")
    elif menu == "2":

        print(name, "\nmember since today\nelo: ", elo, "\ndescription:\n   ", description)
        descripter = input("update description? (y/n): ")
        if descripter == "y":
            description = input("describe yourself:\n")
        elif descripter == "n":
            continue
        else:
            print("invalid")
        input("press enter to go back")
    elif menu == "3":
        print("boi i aint that good at coding, i dont even know how to pretend to have puzzles so im not gonna...")
    elif menu == "4":
        socials = input("SOCIALS | [clubs] , [forums] , [friends] , [live chat] | inputs = (1) , (2) , (3) , (4)\n")
        if socials == "1":
            club_option = input("your clubs are:\n    chess.com community\n    akis budhole\n    pythonic\ninput: (1) , (2) , (3)\n")
            if club_option == 1:
                print("chess.com community club\ndescription:\nofficial club of chess.com\n 50K members\nadmins:\nidk i forgot, was it staerex, wind, anitta?")
                selection = input("SELECT | [notes] , [forums] , [chat] | inputs: (1) , (2) , (3)\n")
                if selection == "1":
                    while True:
                        print("random idiot\n stop spamming\ntroll\nn word\nn word\nn word\nn word\nmod\n i cant lie i dont rlly care\nkob\n bro why is nobody doing anything\naki\n*insert savage roast here*")
                        note = input("add a note? (y/n): ")
                        if note == "y":
                            input("follow guidelines, note:\n")
                            rand = random.randint(1, 5)
                            if rand == 4:
                                ban("violating community guidelines")
                                quit()
                            else:
                                print("server error that we arent gonna fix ;)")
                                break
                        if note == "n":
                            break
                        else:
                            print("error")
                    # forums
                    if selection == "2":
                        while True:
                            print("post")
                            question1 = input("post? (y/n): ")
                            if question1 == "y":
                                input("title:\n")
                                input("body:\n")
                                ban("trolling")
                                quit()
                    # chat
                    if selection == "3":
                        while True:
                            print("message")
                            rand = random.randint(1, 10)
                            input("write message: ")
                            if rand == 4:
                                ban("violating community guidelines")
                                quit()
                            else:
                                print("another server error that we dont care about ;)")
                                break
    elif menu == "5":
        support = input("contact us? (y/n): ")
        if support == "y":
            support_method = input("[staff] , [bot] , [gmail] | inputs = (1) , (2) , (3)\n")
            if support_method == "1":
                while True:
                    counter = 0
                    print("please wait for a response...")
                    time.sleep(2)
                    counter += 1
                    if counter > 150:
                        print("staff unavailable")
                        break
            elif support_method == "2":
                print("we have encountered an error, thats totally our fault and we wont be fixing it")
                question = input("go back? (y/n): ")
                if question == "y":
                    break
                else:
                    continue
            elif support_method == "3":
                print("support@chess.com, but we wont ever respond ;)")
                break
        elif support == "n":
            break
        else:
            print("invalid")