#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char colorList[1000][200] = {'\0'};
unsigned long hashList[1000] = {0};
unsigned long secondList[1000][5] = {0};

unsigned long target;
int total = 0;


FILE *fp;
char line[200];

unsigned long hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c;

    return hash;
}

const char * getMainColor(char *line) {
    char *mainColor = malloc(sizeof(char)*50);
    int i = 0;
    for (; i < strlen(line); i++)
    {
        if (line[i+1] == 'b' && line[i+2] == 'a' && line[i+3] == 'g')
        {
            mainColor[i] = '\0';
            break;
        }
        mainColor[i] = line[i];
    }
    return mainColor;
}

unsigned long * getSecondaryColors(char *lne, int count) {

    unsigned long *secondaryColors = malloc(sizeof(*secondaryColors) * 5);
    int record = 0;
    char temp[50] = {"\0"};

    for (int i = 0, c = 0, v = 0; i < strlen(lne); i++)
    {   
        //check end of line or error
        if (lne[i+2] == '\n') 
        {
            return secondaryColors;
        }
        //check end and stop recording
        if (lne[i+1] == 'b' && lne[i+2] == 'a' && lne[i+3] == 'g' && record == 1)
        {
            secondaryColors[v] = hash(temp);
            secondaryColors[v+1] = 0;
            v++;
            memset(temp, '\0', strlen(temp));
            record = 0;
            c = 0;
        }
        //check if is number and start recording
        if (lne[i] <= 57 && lne[i] >= 48 && record == 0)
        {
            i++;
            record = 1;
            continue;
        }
        if (record == 1)
        {
            temp[c] = lne[i];
            c++;
        }
    }
}

int searchHash(unsigned long search) {
    for (int i = 0; i < 1000; i++)
    {
        if (hashList[i] == 0)
        {
            break;
        }
        
        if (hashList[i] == search)
        {
            return i;
        }
    }
    printf("error searching hash\n");
    return -1;
}

int lookInside(unsigned long bagHash) {
    int valid = 0;
    int b = searchHash(bagHash);
    
    printf("subcolor: %s\n", colorList[b]);
    for (int x = 0; x < 5; x++)
    {
        if (b == -1)
        {
            break;
        }

        if (valid == 1)
        {
            printf("%s is valid\n\n", colorList[b]);
            break;
        }
        
        if (secondList[b][x] == target)
        {
            valid = 1;
            break;
        }
        
        if (secondList[b][x] != 0)
        {
            valid = lookInside(secondList[b][x]);
        } else {
            break;
        }
        
    }
    return valid;
}

void getHashMap(char *line, int c) {
    const char *mainColor = getMainColor(line);
    strcpy(colorList[c], mainColor);
    hashList[c] = hash(colorList[c]);
    unsigned long *temp = getSecondaryColors(line, c);
    for (int i = 0; i < 5; i++)
    {
        unsigned long *t = temp+i;

        if (*t == 0)
        {
            secondList[c][i] = 0;
            break;
        }
        
        secondList[c][i] = *t;
    }
}

void getLines(int c) {

    for (int i = 0; i < 1000; i++)
    {

        if (hashList[i] == 0)
        {
            printf("\n\nEND");
            break;
        }

        unsigned long mainCol = hashList[i];
        int valid = 0;

        for (int x = 0; x < 5; x++)
        {
            if (secondList[i][x] == 0)
            {
                printf("\nempty");
                break;
            }

            if (valid == 1)
            {
                printf("\nvalid parent");
                break;
            }
            
            
            if (secondList[i][x] == target)
            {
                valid = 1;
                break;
            }
            printf("lookinside i: %d x: %d\n", i , x);
            valid = lookInside(secondList[i][x]);
        }
        printf("\ncolor: %s valid: %d\n\n", colorList[i], valid);
        if (valid == 1)
        {
            valid = 0;
            total++;
        }
    }    
}

void getInside(int bagHash) {
    int count = 0;
    int index = searchHash(bagHash);
    while (fgets(line, 1000, fp))
    {
        count++;

        if (count == index )
        {
            
        }
    }
    
    
}

void main() {
    fp = fopen("src.txt", "r");
    target = hash("shiny gold");

    if (fp == NULL)
    {
        printf("error file path");
        return;
    }
    int c = 0;

    while (fgets(line, 1000, fp))
    {
        //obtain hashlist e colorlist
        getHashMap(line, c);
        c++;
    }

    //getInside(target);

    getLines(c);

    printf("\n\n%d", total);

    getchar();
}