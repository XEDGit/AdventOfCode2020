#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int valids;

void getLines() {

    FILE *fp = NULL;
    fp = fopen("src2.txt", "r");

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
                printf("\t\texception");
            }
            
            if (checks == 8)
            {
                valids++;
                printf("\t\tok");
            }
            
            printf(" %d\n\n%d", checks, num);
            exception = 1;
            checks = 0;
            
            continue;
        }

        for (int i = 0; i < strlen(line); i++)
        {

            if (line[i] == '\n')
            {
                break;
            }
            
            if (line[i] == ' ' || i == 0)
            {
                if (i == 0)
                {
                    i--;
                }
                
                temp = line[i+1];
                int tmpVal = 0;
                
                int t = 0;
                if (temp == 'c')
                {
                    checks++;
                    printf("- %c ", temp);
                    i += 4;
                    exception = 0;
                } 
                else if (temp == 'b') 
                {
                    t = 0;
                    int x = 0;
                    int k = 0;

                    for (x = i+5, k = 0; k < 5;k++, x++)
                    {
                        
                        if (k == 4)
                        {
                            if (line[x] == ' ' || line[x] == '\n')
                            {
                                tmpVal = 1;
                            }
                            break;
                        }

                        t = t * 10;
                        t += line[x] - '0';
                    }
                    
                    if (t >= 1920 && t <= 2002 && tmpVal == 1)
                    {
                        tmpVal = 0;
                        t = 0;
                        printf("- %c ", temp);
                        checks++;
                    }

                    tmpVal = 0;
                    t = 0;

                    if (i == -1)
                    {
                        i++;
                    }

                    i += 4;
                    
                } 
                else if (temp == 'i') 
                {
                    t = 0;
                    int x = 0;
                    int k = 0;

                    for (x = i+5, k = 0; k < 5;k++, x++)
                    {
                        
                        if (k == 4)
                        {
                            if (line[x] == ' ' || line[x] == '\n')
                            {
                                tmpVal = 1;
                            }
                            break;
                        }
                        
                        t = t * 10;
                        t += line[x] - '0';
                    }
                    
                    if (t >= 2010 && t <= 2020 && tmpVal == 1)
                    {
                        tmpVal = 0;
                        t = 0;
                        printf("- %c ", temp);
                        checks++;
                    }

                    tmpVal = 0;
                    t = 0;

                    if (i == -1)
                    {
                        i++;
                    }

                    i += 4;
                }
                else if (temp == 'e') 
                {
                    if (line[i+2] == 'y')
                    {
                        t = 0;
                        int x = 0;
                        int k = 0;

                        for (x = i+5, k = 0; k < 5;k++, x++)
                        {
                            
                            if (k == 4)
                            {
                                if (line[x] == ' ' || line[x] == '\n')
                                {
                                    tmpVal = 1;
                                }
                                break;
                            }
                            
                            t = t * 10;
                            t += line[x] - '0';
                        }
                        
                        if (t >= 2020 && t <= 2030 && tmpVal == 1)
                        {
                            tmpVal = 0;
                            t = 0;
                            checks++;
                            printf("- %c ", temp);
                        }

                        tmpVal = 0;
                        t = 0;

                        if (i == -1)
                        {
                            i++;
                        }

                        i += 4;
                    } else {
                    
                        char tempStr[10] = {'\0'};
                        int x = 0;
                        int k = 0;
                        for (x = i+5, k = 0; k < 10; x++, k++)
                        {
                            if (k > 3)
                            {
                                tempStr[k] = '\0';
                            }
                            else if (k == 3)
                            {
                                if (line[x] == ' ' || line[x] == '\n')
                                {
                                    tmpVal = 1;
                                }
                            } else {
                                tempStr[k] = line[x];
                            }
                            
                        }

                        if (tmpVal == 1)
                        {
                            tmpVal = 0;
                            char *eyes[] = {"amb", "blu", "brn", "grn", "gry", "hzl", "oth"};
                            for (int r = 0; r < 7; r++)
                            {
                                if (strcmp(tempStr, eyes[r]) == 0)
                                {
                                    checks++;
                                    printf("- %c ", temp);
                                    break;
                                }
                            }
                            
                        }
                        i+=4;
                        
                    }
                    
                } 
                else if (temp == 'h') 
                {
                    if (line[i+2] == 'g')
                    {
                        t = 0;
                        int x = 0;
                        int k = 0;

                        for (x = i+5, k = 0; k < 6;k++, x++)
                        {
                            if (line[x] > 57 || line[x] < 48)
                            {
                                printf("%d", k);
                                break;
                            }
                            
                            t = t * 10;
                            t += line[x] - '0';
                        }

                        char tempStr[5] = {'\0'};
                        tempStr[0] = line[x];
                        tempStr[1] = line[x+1];

                        printf(" %d|%s ", t, tempStr);

                        if (strcmp(tempStr, "cm") == 0) 
                        {
                            if (t >= 150 && t<= 193) {
                                checks++;
                                tmpVal = 0;
                                printf("- %c ", temp);
                            }
                        }

                        if (strcmp(tempStr, "in") == 0)
                        {
                            if (t >= 59 && t<= 76) {
                                checks++;
                                tmpVal = 0;
                                printf("- %c ", temp);
                            }
                        }
                        

                    } else {
                        if (line[i+5] == '#')
                        {
                            int x = 0;
                            tmpVal = 0;
                            int k = 0;
                            for (int r = i+5, k = 0; k <= 7; r++, k++)
                            {
                                if (k == 7)
                                {
                                    if (line[r] == ' ' || line[r] == '\n')
                                    {
                                        tmpVal = 1;
                                    }
                                    break;
                                }

                                if (line[r] >= 48 && line[r] <= 57)
                                {
                                    x++;
                                }

                                if (line[r] >= 97 && line[r] <= 102)
                                {
                                    x++;
                                }
                            }
                            if (x == 6)
                            {
                                checks++;
                                printf("- %c ", temp);
                                tmpVal = 0;
                            }
                            
                            
                        }
                        
                    }
                    
                    i += 4;
                } 
                else if (temp == 'p') 
                {
                    int x = 0;
                    int k = 0;

                    for (x = i+5, k = 0; k < 10;k++, x++)
                    {

                        if (line[x] != ' ' && line[x] != '\n')
                        {
                            tmpVal++;
                        } else {
                            break;
                        }
                        
                    }
                    
                    if (tmpVal == 9)
                    {
                        tmpVal = 0;
                        checks++;
                        printf("- %c ", temp);
                    }

                    tmpVal = 0;

                    if (i == -1)
                    {
                        i++;
                    }

                    i += 4;
                }

            }
            
        }
        
    }

    num++;
    if (checks == 7 && exception == 1)
    {
        valids++;
        printf("\t\texception");
    }
    
    if (checks == 8)
    {
        valids++;
        printf("\t\tok");
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