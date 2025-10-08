print("welcome to my quiz")
playing = input("do you wanna play? y/n: ")

if playing.lower() == "y":
    print("whatchu know about piano >:D")
elif playing.lower() == "n":
    print("ok gtfo")
    quit()
else:
    print("invalid input")
    quit()

answer = 0

q1 = input("how many keys are in a piano? ")

if q1 == "88":
    print("correct, thats basic knowledge")
    answer += 1
else:
    print("NO! are you domb? what do you use? a 61 key?")

q2 = input("what do you call music in classical music? ")

if q2.lower() == "piece":
    answer += 1
    print("a fellow classical music enjoyer huh")
elif q2 == "song":
    print("are you brain dead? get outta here")
    quit()
else:
    print("nah you trippin")

q3 = input("who wrote harder pieces? liszt or chopin? ")

if q3.lower() == "liszt":
    print("correct, transcendental etudes are a nightmare ngl")
    answer += 1
elif q3.lower() == "alkan":
    print("marry me")
else:
    print("nahhhhhh")
q4 = input("liszt appassionata or beethoven appassionata? ")

if q4.lower() == "both":
    answer += 1
print("both is good")

q5 = input("is pogorelich any good? y/n ")

if q5.lower() == "y":
    print("YES! w taste my guy")
    answer += 1
elif q5.lower() == "n":
    print("bruh pogo goated, -999999 points")
    answer -= 999999
else:
    print("bruh can you just do the quiz like a normal person")

q6 = input("is atonal music any good? ")

if q6.lower() == "n":
    print("correct, atonal music is literally just noise")
    answer += 1
elif q6.lower() == "y":
    print("tf is wrong with you, get outta here")
    quit()
else:
    print("stop trying to screw with my quiz")

print("you got " + str(answer) + "/6")