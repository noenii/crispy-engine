#include <stdio.h>

void printSquares(char *squares);

int main() {
    int filled = 0;
    char squares[] = "---------";
    while(filled != 9) {
        int x;
        printf("Enter X: ");
        scanf("%d", &x);
        int y;
        printf("Enter Y: ");
        scanf("%d", &y);
        int cnv = (3 * y) + x;
        if(squares[cnv] == '-') {
            if(filled % 2 == 0) {
                squares[cnv] = 'O';
            }   else {
                squares[cnv] = 'X';
            }
            printSquares(squares);
            for(int i = 0; i < 3; i++) {
                if(squares[i] != '-' &&
                squares[i] == squares[i+3] &&
                squares[i+3] == squares[i+6]) {
                    printf("player %d won\n", (filled % 2) + 1);
                    return 0;
                }
            }
            for(int i = 0; i < 9; i += 3) {
                if(squares[i] != '-' &&
                squares[i] == squares[i+1] &&
                squares[i+1] == squares[i+2]) {
                    printf("player %d won\n", (filled % 2) + 1);
                    return 0;
                }
            }
            if(squares[0] != '-' &&
            squares[0] == squares[4] &&
            squares[4] == squares[8]) {
                printf("player %d won\n", (filled % 2) + 1);
                return 0;
            }

            if(squares[2] != '-' &&
            squares[2] == squares[4] &&
            squares[4] == squares[6]) {
                printf("player %d won\n", (filled % 2) + 1);
                return 0;
            }
            filled++;
        }   else {
            printf("invalid\n\n");
        }
    }
    if(filled == 9) {printf("draw\n");}
    return 0;
}

void printSquares(char *squares) {
    for(int i = 0; i < 9; i++) {
        if(i % 3 == 0) {printf("\n");}
        printf("[%c] ", squares[i]);
    }
    printf("\n\n");
    return;
}