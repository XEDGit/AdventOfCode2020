#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int rows = 128;
const int cols = 8;

void getLines() {

    FILE *fp = NULL;
    fp = fopen("src.txt", "r");

    if (fp == NULL)
    {
        return;
    }

    char line[20];
    int c = 0;

    while (fgets(line, 1000, fp))
    {
        //printf("ciao\n");
        int seatid = 0;
        int maxRw = rows;
        int maxCl = cols;
        int minRw = 0;
        int minCl = 0;
        for (int i = 0; i < strlen(line); i++)
        {
            

            if (line[i] == 'B')
            {
                minRw = (minRw+maxRw)/2;
            } 
            else if (line[i] == 'F') 
            {
                maxRw = (minRw+maxRw)/2-1;
            } 
            else if (line[i] == 'R')
            {
                minCl = (minCl+maxCl)/2;
            } 
            else if (line[i] == 'L') 
            {
                maxCl = (minCl+maxCl)/2-1;
            }
        }
        seatid = maxRw * 8 + maxCl;
            
        if (c < seatid)
        {
            printf("%d / %d - %d / %d\n", minRw, maxRw, minCl, maxCl);
            c = seatid;
        }
    }

    printf("%d",c);
}

void main() {
    getLines();
    //getchar();
}