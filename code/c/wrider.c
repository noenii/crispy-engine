#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    FILE *file;
    bool exists = false;
    if((file = fopen("smth.txt","r"))!=NULL) {
        exists = true;
        fclose(file);
    }   else {
        file = fopen("smth.txt", "w");
    }
    if(exists == true) {
        file = fopen("smth.txt","a");
    }
    bool running = true;
    while(running) {
        char temp[100];
        printf("Append to file: ");
        fgets(temp, sizeof(temp), stdin);
        temp[strcspn(temp, "\n")] = 0;
        fprintf(file, "%s", temp);
        fprintf(file, "%c", '\n');
        if (strcmp(temp, "quit") == 0) {
            break;
        }
    }
}