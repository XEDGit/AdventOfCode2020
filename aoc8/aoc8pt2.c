#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		checkList[700] = {0};
char	*text;
int		acc = 0;
int		cur = 1;
int		line = 1;

void nextLine()
{
	while (text[cur] != '\n')
		cur++;
	cur++;
	//line++;
}

void startLine()
{
	cur--;
	while (text[cur] != '\n')
		cur--;
	cur++;
}

void prevLine()
{
	while (text[cur] != '\n')
		cur--;
	cur--;
	while (text[cur] != '\n')
		cur--;
	cur++;
	//line--;
}

int readvalue()
{
	while (text[cur] != '-' && text[cur] != '+')
		cur++;
	char	temp[6] = {0};
	int		ind = 1;
	temp[0] = text[cur];
	cur++;
	while (text[cur] >= '0' && text[cur] <= '9')
	{
		temp[ind] = text[cur];
		ind++;
		cur++;
	}
	temp[ind] = 0;
	startLine();
	return (atoi(temp));
}

void	jump(int n)
{
	int i = 0;
	if (n > 0)
	{
		while (i < n)
		{
			nextLine();
			i++;	
		}
	}
	else
	{
		while (i > n)
		{
			prevLine();
			i--;	
		}
	}
	line += n;
}

void readLine()
{
	int	value = 0;
	checkList[line] = 1;
	if (text[cur] == 'j')
	{
		value = readvalue();
		jump(value);
	}
	else if (text[cur] == 'a')
	{
		value = readvalue();
		acc += value;
		nextLine();
		line++;
	}
	else
	{
		nextLine();
		line++;
	}
	printf("line %d: %c %d\n", line, text[cur], value);
}

int main()
{
	FILE	*fp;
	int		i = 0;
	fp = fopen("src.txt", "r");
	long fsize = 10000;
	text = malloc(fsize + 1);
	fseek(fp, 0, SEEK_SET);
	fread(text, 1, fsize, fp);
	fclose(fp);
	while (checkList[line] != 1)
	{
		readLine();
	}
	printf("%d\n", acc);
}