#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int min, max, minlen, maxlen;
    char checkChar;
} MiMaP;

int valids;
int ct;

FILE *fp = NULL;

int getLines() {

    if (fp == NULL)
    {
        return 0;
    }

    char line[45];
    int c = 0;

    while (fgets(line, 1001, fp))
    {
        MiMaP bl = {0};
        int temp = 0;

        if (line[1] == '-')
        {
            bl.min = line[0] - '0';
            bl.minlen = 1;
            if (line[3] == ' ')
            {
                bl.max = line[2] - '0';
                bl.maxlen = 1;
            } else {
                temp = line[2] - '0';
                temp = temp * 10 + (line[3] - '0');
                bl.max = temp;
                bl.maxlen = 2;
            }
            
        } else {
            temp = line[0] - '0';
            temp = temp * 10 + (line[1] - '0');
            bl.min = temp;
            bl.minlen = 2;
            if (line[4] == ' ')
            {
                bl.max = line[3] - '0';
                bl.maxlen = 1;
            } else {
                temp = line[3] - '0';
                temp = temp * 10 + (line[4] - '0');
                bl.max = temp;
                bl.maxlen = 2;
            }
        }

        int check = bl.minlen + bl.maxlen + 2;
        bl.checkChar = line[check];
        check += 2;
        int c = 0;

        for (int i = check; i < 45 - check; i++)
        {
            if (line[i] == '\n')
            {
                ct++;
                break;
            }
            
            
            if (line[i] == bl.checkChar)
            {
                c++;
            }
        }

        if (c <= bl.max && c >= bl.min)
        {
            valids++;
        }
        
    }
    
    fclose(fp);
    return 1;

}



int main() {

    ct = 1;
    valids = 0;
    fp = fopen("src.txt", "r");
    getLines();
    printf("searched in %d lines and found %d valids", ct, valids);
}