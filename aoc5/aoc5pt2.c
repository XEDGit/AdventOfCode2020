#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int rows = 127;
const int cols = 7;

void getLines() {

    FILE *fp = NULL;
    fp = fopen("src.txt", "r");

    if (fp == NULL)
    {
        return;
    }

    char line[20];
    int c = 0;
    int seats[128][8] = {0};

    while (fgets(line, 1000, fp))
    {
        
        int maxRw = rows;
        int maxCl = cols;
        int minRw = 0;
        int minCl = 0;
        for (int i = 0; i < strlen(line); i++)
        {
            

            if (line[i] == 'B')
            {
                minRw = (minRw+maxRw)/2+1;
            } 
            else if (line[i] == 'F') 
            {
                maxRw = (minRw+maxRw)/2-1;
            } 
            else if (line[i] == 'R')
            {
                minCl = (minCl+maxCl)/2+1;
            } 
            else if (line[i] == 'L') 
            {
                maxCl = (minCl+maxCl)/2-1;
            }
        }
        seats[minRw][minCl] = 1;
    }
    printf("%d\n", c);

    int records[50][2] = {0};
    int count = 0;

    for (int i = 0; i < 128; i++)
    {
        c++;
        printf("%d ", c);
        for (int x = 0; x < 8; x++)
        {
            if (i < 100 && i > 30&& seats[i][x] == 0)
            {
                records[count][0] = i;
                records[count][1] = x;
                //printf("%d - %d\n", i, x);
                count++;
            }
            printf("%d", seats[i][x]);
        }
        printf("\n");
    }
    
    printf("row = %d col = %d", records[0][0], records[0][1]);
    
}

void main() {
    getLines();
    //getchar();
}