#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int trees, x, y;
} Agent;

Agent ag;

void getLines() {

    FILE *fp = NULL;
    fp = fopen("src.txt", "r");

    if (fp == NULL)
    {
        printf("error");
        return;
    }

    char line[32];

    while (fgets(line, 324, fp))
    {   
        ag.x += 3;
        ag.y++;

        if (ag.x >= 31)
        {
            int temp = ag.x - 31;
            ag.x = 0 + temp;
        }
        
        

        if (line[ag.x] == '#')
        {
            ag.trees++;
        }
        
    }

    fclose(fp);

}

void main() {

    ag.trees = 0;
    ag.x = 0;
    ag.y = 0;
    
    getLines();
    printf("x: %d y: %d trees: %d", ag.x, ag.y, ag.trees);
}