#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *numArr;

int* getLines() {

    FILE *fp = NULL;
    fp = fopen("src.txt", "r");

    if (fp == NULL)
    {
        return 0;
    }

    char line[6];
    int c = 0;

    while (fgets(line, 200, fp))
    {
        numArr[c] = atoi(line);
        c++;
    }
        
}

void sums() {

    int len = 199;
    int c = 0;

    int skipc = 0;

    for (int i = 0; i < len; i++)
    {
        for (int y = len ; y > 0; y--) {

            if (y == i)
            {
                printf("skip1");
                continue;
            }
            
            for (int x = 0 ; x < len; x++)
            {
                if (x == y || x == i)
                {
                    skipc++;
                    //printf("skip2 %d , i:%d , y:%d , x:%d\n", skipc, i,y,x);
                    continue;
                }
                
                if (numArr[i] + numArr[x] + numArr[y] == 2020)
                {
                    int out1, out2, out3;

                    out1 = numArr[i];
                    out2 = numArr[y];
                    out3 = numArr[x];

                    printf("nums: %d, %d, %d\nsum: %d", out1, out2, out3, out1*out2*out3);

                    getchar();
                    return;
                    
                }
                
            }
        }
        
    }    
}

int main() {
    numArr = malloc(sizeof(int)*200);
    getLines();
    sums();

    getchar();
}

