#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int valids;

void getLines() {

    FILE *fp = NULL;
    fp = fopen("src.txt", "r");

    if (fp == NULL)
    {
        printf("error");
        return;
    }

    char line[100];
    int prevPass = 0;
    int checks = 0;
    int exception = 1;
    char temp;
    int num = 1;
    

    while (fgets(line, 1100, fp))
    {   
        if (line[0] == '\n')
        {
            num++;
            if (checks == 7 && exception == 1)
            {
                valids++;
                printf("valid exception");
            }
            
            if (checks == 8)
            {
                valids++;
                printf("valid");
            }
            
            printf(" %d\n\n%d", checks, num);
            exception = 1;
            checks = 0;
            
            continue;
        }

        printf(" - %c ", line[0]);

        if (line[0] == 'c')
        {
            printf(" ex first ");
            exception = 0;
        }

        checks++;
        

        for (int i = 1; i < strlen(line); i++)
        {
            if (line[i] == '\n')
            {
                break;
            }
            
            
            if (line[i] == ' ')
            {
                temp = line[i+1];
                printf("- %c ", temp);
                if (temp == 'c')
                {
                    printf(" ex ");
                    exception = 0;
                }
                
                checks++;

            }
            
        }
        
    }

    num++;
    if (checks == 7 && exception == 1)
    {
        valids++;
        printf("valid exception");
    }
    
    if (checks == 8)
    {
        valids++;
        printf("valid");
    }
    
    printf(" %d\n\n", checks);
    exception = 1;
    checks = 0;

    fclose(fp);

}

void main() {
    valids = 0;
    getLines();
    printf("valids: %d", valids);
}