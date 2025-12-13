#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void prntInf();
void menu(int night);
void jumpscare(int who);

int main() {        //not finished yet
    const char *cam1A[12][8] = {    //SHIFT BY ONE!
        {       //1
            NULL
        },  {       //2
            "+-------------------------------+",
            "|        (L. Hall Corner)       |",
            "|                               |",
            "|                               |",    //
            "|                               |",
            "|                               |",
            "|                               |",
            "+-------------------------------+"
        },  {       //3
            "+-------------------------------+",
            "|        (R. Hall Corner)       |",
            "|                               |",
            "|                               |",    //
            "|                               |",
            "|                               |",
            "|                               |",
            "+-------------------------------+"
        },  {       //4
            "+-------------------------------+",
            "|           (L. Hall)           |",
            "|                               |",
            "|                               |",    //
            "|                               |",
            "|                               |",
            "|                               |",
            "+-------------------------------+"
        },  {       //5
            "+-------------------------------+",
            "|           (R. Hall)           |",
            "|                               |",
            "|                               |",    //
            "|                               |",
            "|                               |",
            "|                               |",
            "+-------------------------------+"
        },  {       //6
            "+-------------------------------+",
            "|           (CLOSET)            |",
            "|                               |",
            "|                               |",    //
            "|                               |",
            "|                               |",
            "|                               |",
            "+-------------------------------+"
        },  {       //7
            "+-------------------------------+",
            "|           (KITCHEN)           |",
            "|                               |",
            "|                               |",    //
            "|                               |",
            "|                               |",
            "|                               |",
            "+-------------------------------+"
        },  {       //8
            "+-------------------------------+",
            "|         (PIRATE COVE)         |",
            "|                               |",
            "|                               |",    //
            "|                               |",
            "|                               |",
            "|                               |",
            "+-------------------------------+"
        },  {       //9
            "+-------------------------------+",
            "|          (BACKSTAGE)          |",
            "|                               |",
            "|                               |",    //
            "|                               |",
            "|                               |",
            "|                               |",
            "+-------------------------------+"
        },  {       //10
            "+-------------------------------+",
            "|         (DINING AREA)         |",
            "|                               |",
            "|                               |",    //
            "|                               |",
            "|                               |",
            "|                               |",
            "+-------------------------------+"
        },  {       //11
            "+-------------------------------+",
            "|          (BATHROOMS)          |",
            "|                               |",
            "|                               |",    //
            "|                               |",
            "|                               |",
            "|                               |",
            "+-------------------------------+"
        },  {       //12
            "+-------------------------------+",
            "|            (STAGE)            |",
            "|                               |",
            "|                               |",    //
            "|                               |",
            "|                               |",
            "|                               |",
            "+-------------------------------+"
        }
    };
    const char *camSelect[11] = {
        "                                    ",
        "               [12]                 ",
        "                 |                  ",
        "  [9]---[10]-----+-----[11]         ",
        "                 |                  ",
        "  [8]-----+------+------+-------+   ",
        "          |             |       |   ",
        "  [6]----[4]           [5]     [7]  ",
        "          |             |           ",
        "         [2]----[1]----[3]          ",
        "                                    "
    };

    int hour = 0;
    int night = 1;

    bool right_door_open = true;
    bool left_door_open = true;

    bool running = true;

    while(running) {
        menu(night);
        break;
    }

    return 0;
}

void prntInf() {
    printf("This is a remake of FNAF 1 by Scott Cawthon I made as a learning project.\n12/13/25\n");
    return;
}

void menu(int night) {
    bool running = true;
    while(running) {
        int option;
        if(night == 1) {
            printf("Select: Play (1) | Info (2) | Exit (3)\n");
            scanf("%d", &option);
            getchar();
            switch(option) {
                case 1: {
                    printf("Starting game...\n");
                    return;
                }
                case 2: {
                    prntInf();
                    break;
                }
                case 3: {
                    exit(EXIT_SUCCESS);
                }
                default: {
                    printf("Invalid Input.\n");
                    break;
                }
            }
        }   else if(night == 7) {
            printf("Select: Night %d - Custom Night (1) | Restart (2) | Info (3) | Exit (4)\n", night);
            scanf("%d", &option);
            getchar();
            switch(option) {
                case 1: {
                    return;
                }
                case 2: {
                    printf("Restarting...\n");
                    return;
                }
                case 3: {
                    prntInf();
                    break;
                }
                case 4: {
                    exit(EXIT_SUCCESS);
                }
                default: {
                    printf("Invalid Input.\n");
                    break;
                }
            }
        }   else {
            printf("Select: Continue Night %d (1) | Restart (2) | Info (3) | Exit (4)\n", night);
            scanf("%d", &option);
            getchar();
            switch(option) {
                case 1: {
                    return;
                }
                case 2: {
                    printf("Restarting...\n");
                    return;
                }
                case 3: {
                    prntInf();
                    break;
                }
                case 4: {
                    exit(EXIT_SUCCESS);
                }
                default: {
                    printf("Invalid Input.\n");
                    break;
                }
            }
        }
    }
}

void jumpscare(int who) {
    system("cls");
    char *name;
    switch(who) {
        case 1: {
            name = "Freddy";
            break;
        }
        case 2: {
            name = "Bonnie";
            break;
        }
        case 3: {
            name = "Chica";
            break;
        }
        case 4: {
            name = "Foxy";
            break;
        }
        case 5: {
            name = "Golden Freddy";
            break;
        }
    }
    printf("You were killed by %s", name);
    return;
}






