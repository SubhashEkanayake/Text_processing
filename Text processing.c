//CSCI 12042-Assignment 2
//CS/2020/009

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

int main() {
    printf("\t\t\t\t******************WELCOME*******************\n\n");
    FILE *file;
    char word[MAX_WORD_LENGTH];  //variables declaration
    char fname[MAX_WORD_LENGTH];
    int numWords = 0;
    int totalLength = 0;
    int run=1;

    while(run==1){
        printf("\n\t\t==>Enter your file name('filename'.txt):");   //get file name
        scanf("%s",&fname);
        file = fopen(fname, "r");   //read file

        //entered file name that if it was a wrong input
        if (file == NULL) {
            printf("\n\t\t\t\t\t---Error opening the file---\n");
        }

        //when entered correct file name
        else if(1){
            while (fscanf(file, "%s", word) == 1) {  // Remove any punctuation characters from the word
                int len = strlen(word);
                for (int i = 0; i < len; i++) {
                    if (ispunct(word[i])) {
                        for (int j = i; j < len; j++) {
                            word[j] = word[j + 1];
                        }
                        len--;
                        i--;
                    }
                }

            if (len > 0) {
                numWords++;
                totalLength += len;
                }
            }

            fclose(file);   //close file

            printf("\n\t\t\t==>Number of words in the file: %d\n", numWords);
            printf("\n\t\t\t==>Average word length: %.2f\n", (float)totalLength / numWords);


                }

            printf("\n\t\t==>Do you want to try another one(Y-1,N-0): ");  //if you want to try furthermore
            scanf("%d",&run);

            }

            if(run==0){
                printf("\n\t\t\t\t\t\t***END***\n");   //exit from the program
            }

    getch();

    return 0;


}


