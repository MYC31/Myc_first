#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"
#include "string.h"

/**
 * @brief generate a file consists of 50000 lines of words, 
 *        half line has a substring "computer", and is repeated.
 *        the clone one is stripped of "computer".
 *        
 *        0 ~ 9 : 48 ~ 57
 *        a ~ z : 97 ~ 122
 * 
 */


void file_create(const char *_addr)
{
    FILE *file = fopen(_addr, "w");
    size_t line = 250000u;
    srand(time(NULL));

    // char *str = NULL;
    for (size_t i = 0; i < line; i++) {
        // str = (char *)malloc(abs(rand())%20 * sizeof(char));
        char str[abs(rand())%100+1];
        for (size_t j = 0; j < strlen(str); j++) {
            if (abs(rand()) % 2 == 0) 
                str[j] = abs(rand())%10 + 48;
            else
                str[j] = abs(rand())%26 + 97;
        }
        strcat(str, "computer\n");
        fputs(str, file);
        fputs(str, file);
        // free(str);
    }   

    fclose(file);
}

void file_show() 
{
    FILE *file = fopen("words.txt", "r");
    int ch;

    while ((ch = fgetc(file)) != '\n') {
        printf("%c", ch);
    }

    fclose(file);
}

int main()
{
    file_create("words.txt");
    return 0;
}