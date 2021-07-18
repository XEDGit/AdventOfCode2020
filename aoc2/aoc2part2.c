#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int min, max, minlen, maxlen;
    char checkChar;
} MiMaP;

int valids, invalids;
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

        if (line[check+bl.min] == bl.checkChar)
        {
            c++;
        }

        if (line[check+bl.max] == bl.checkChar)
        {
            c++;
        }

        if (c == 1)
        {
            printf("\n%s min: %d | max: %d | check: %d | c:%d\n", line, bl.min, bl.max, check, c);
            valids++;
        } else {
            invalids++;
        }
        
    }
    
    fclose(fp);
    return 1;

}



int main() {

    ct = 0;
    valids = 0;
    invalids = 0;
    fp = fopen("src.txt", "r");
    getLines();
    printf("%d | ct:%d | %d", valids, ct, invalids);
}