import pygame

pygame.init()

screen = pygame.display.set_mode((550, 550))

running = True

doggie = pygame.image.load('images (4).jpg').convert()
scaled_doggie = pygame.transform.scale(doggie, (doggie.get_width() * 2, doggie.get_height() * 2))

while running:

    screen.blit(scaled_doggie, (50, 50))

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    pygame.display.flip()

pygame.quit()