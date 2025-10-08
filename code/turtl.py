import turtle
import time
import random

WIDTH, HEIGHT = 500, 500
COLORS = ['red', 'green', 'blue', 'orange', 'black', 'yellow', 'purple', 'cyan', 'brown', 'pink']


def get_num():
    while True:
        answer = input('how many turtles? (2 - 10): ')
        if answer.isdigit():
            answer = int(answer)
            if 2 <= answer <= 10:
                return answer
            else:
                print('not in range')
        else:
            print('invalid')

def get_screen():
    screen = turtle.Screen()
    screen.setup(WIDTH, HEIGHT)
    screen.title('turtle racing')

def get_turtles(colors):
    spacingX = WIDTH // (len(colors) + 1)
    turtles = []
    for i, color in enumerate(colors):
        racer = turtle.Turtle()
        racer.color(color)
        racer.shape('turtle')
        racer.left(90)
        racer.penup()
        racer.setpos(-WIDTH // 2 + (i + 1) * spacingX, -HEIGHT // 2 + 20)
        racer.pendown()
        turtles.append(racer)
    return turtles

def race(colors):
    turtles = get_turtles(colors)
    
    while True:
        for racer in turtles:
            racer.forward(random.randint(1, 20))

            x, y = racer.pos()
            if y >= HEIGHT // 2 - 10:
                return colors[turtles.index(racer)]

num = get_num()
get_screen()

random.shuffle(COLORS)
colors = COLORS[:num]
winner = race(colors)
print(f'{winner} wins')
time.sleep(5)