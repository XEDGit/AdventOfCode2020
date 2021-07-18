#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int trees, x, y;
} Agent;

Agent ag;

void getLines(int x, int y) {

    ag.trees = 0;
    ag.x = 0;
    ag.y = 0;

    FILE *fp = NULL;
    fp = fopen("src2.txt", "r");

    if (fp == NULL)
    {
        printf("error");
        return;
    }

    char line[32];

    int c = 0;

    while (fgets(line, 324, fp))
    {   
        ag.x += x;
        ag.y += y;
        c++;

        if (ag.x >= 31)
        {
            int temp = ag.x - 31;
            ag.x = 0 + temp;
        }

        if (c != ag.y)
        {
            ag.x -= x;
            ag.y -= y;
            continue;
        }

        if (line[ag.x] == '#')
        {
            line[ag.x] = 'X';
            ag.trees++;
        } else {
            line[ag.x] = '0';
        }

        //printf("%s", line);
        
    }

    fclose(fp);

}

void main() {

    int records[5];
    
    getLines(1, 1);
    printf("\n\tx: %d y: %d trees: %d\n\n", ag.x, ag.y, ag.trees);
    records[0] = ag.trees;

    getLines(3, 1);
    printf("\n\tx: %d y: %d trees: %d\n\n", ag.x, ag.y, ag.trees);
    records[1] = ag.trees;

    getLines(5, 1);
    printf("\n\tx: %d y: %d trees: %d\n\n", ag.x, ag.y, ag.trees);
    records[2] = ag.trees;

    getLines(7, 1);
    printf("\n\tx: %d y: %d trees: %d\n\n", ag.x, ag.y, ag.trees);
    records[3] = ag.trees;

    getLines(1, 2);
    printf("\n\tx: %d y: %d trees: %d\n\n", ag.x, ag.y, ag.trees);
    records[4] = ag.trees;

    printf("\n\tresult: %ld", records[0] * records[1] * records[2] * records[3] * records[4]);
}