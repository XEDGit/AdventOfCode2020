#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tot = 0;

char group[10][30] = {'\0'};
int g = 0;

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

int checkstr(char *store, int i, int x, int nstr) {
    for (int p = 0; p < nstr; p++)
    {
        if (group[i][x] == store[p])
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
            char store[30] = {'\0'};
            int nstr = 0;
            for (int i = 0; i < 10; i++)
            {
                char temp[30];
                
                for (int x = 0; x < 30; x++)
                {
                    int check = 0;
                    if (group[i][x] == '\0' || checkstr(store, i, x, nstr) == 1)
                    {
                        break;
                    }

                    for (int z = 0; z < 10; z++)
                    {
                        if (z == i)
                        {
                            continue;
                        }
                        
                        for (int y = 0; y < 30; y++)
                        {
                            if (group[z][y] == '\0')
                            {
                                break;
                            }                       

                            if (group[z][y] == group[i][x])
                            {
                                int ce = checkstr(store, i, x, nstr);
                                
                                if (ce == 0)
                                {
                                    store[nstr] = group[i][x];
                                    nstr++;
                                }
                                check++;
                                break;
                            }
                        }
                        
                    }

                    if (check == g-1)
                    {
                        tot++;
                    }
                    
                }
            }

            for (int i = 0; i < 10; i++)
            {
                strcpy(group[i], "");
            }
            
            g = 0;
            continue;
        }
        

        for (int i = 0; i < strlen(line); i++)
        {
            if (line[i] == '\n')
            {
                strcpy(group[g], stored);
                g++;
                
                c = 0;
                free(stored);
                stored = malloc(sizeof(char)*28);
                break;
            }
            
            if (checkStored(line[i]) == 0)
            {
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
    printf("\n\ttot: %d", tot);
}

void main() {
    
    stored = malloc(sizeof(char)*28);
    getLines();

}
