#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tot = 0;

char *stored;

int checkStored(char ch) {
        
    for (int x = 0; x < 28; x++)
    {
        if (stored[x] == '\0')
        {
            break;
        }
        
        if (stored[x] == ch)
        {
            return 1;
        }
    }
    return 0;
}

void getLines() {

    FILE *fp = NULL;
    fp = fopen("src.txt", "r");

    if (fp == NULL)
    {
        return;
    }

    char line[100];
    
    int c = 0;

    while (fgets(line, 3000, fp))
    {
        
        if (line[0] == '\n')
        {
            printf("stored: %s //end\n", stored);
            free(stored);
            stored = malloc(sizeof(char)*28);
            stored[0] = '\0';
            tot += c;
            c = 0;
            continue;
        }

        for (int i = 0; i < strlen(line); i++)
        {
            if (line[i] == '\n')
            {
                break;
            }
            
            if (checkStored(line[i]) == 0)
            {
                printf("\ntot: %d / c: %d\n", tot, c);
                stored[c] = line[i];
                if (c < 28)
                {
                    stored[c+1] = '\0';
                }
                c++;
                continue;
            }
        }
    }
    tot += c;
    printf("\n\n\ttot: %d", tot);
}

void main() {
    
    stored = malloc(sizeof(char)*28);
    getLines();

}
