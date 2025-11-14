#include <stdio.h>

int main() {
    //files

    FILE *pFile;    //first create a pointer with the FILE datatype
    //pFile = fopen(name, mode);    open a file

    //r = read, reads a file
    //w = write, overwrite a file if it exists, create one if it doesnt
    //a = append


    //reading

    pFile = fopen("13.c", "r");

    if(pFile == NULL) {
        printf("Not able to open the file.");   //good practice to check if a file exists
    }
    char content[100];  //a string to store 100 characters

    //fgets(result, size, pointer);   ig fgets "transfers" the text to the variable provided

    //result is the variable to "transfer" to
    //size is the maximum amount of characters to read, should not go above the string size
    //pointer is the pointer for the file

    while(fgets(content, 100, pFile)) {
        printf("%s", content);  //fgets can only read one line at a time, so use a loop to print out everything
    }   //the variable is limited dont forget, if there is a line with more char... idk what will happen tbh, wont be stored or just throw an error

    fclose(pFile);  //close the file when your done


    //creating files

    FILE *pWrite;
    pWrite = fopen("OOPisGay.txt", "w");    //dont forget if it does exist, the file will be overwritten

    fprintf(pWrite, "real chads write in assembly\n");  //fprintf writes to the file, same logic as printf


    //appending

    FILE *pAppend;
    pAppend = fopen("OOPisGay.txt", "a");

    fprintf(pAppend, "C is just abstracted assembly, so its pretty based"); //same as writing

    
    fclose(pWrite);
    fclose(pAppend);

    return 0;
}