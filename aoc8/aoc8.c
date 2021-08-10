#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		*checkList;
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

int readLine(int i)
{
	int	value = 0;
	checkList[line] += 1;
	if (checkList[line] > 10)
		return (0);
	printf("line %d: %c", line, text[cur]);
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
	printf(" %d\n", value);
	return (1);
}

void changeline(int i)
{
	int temp = 1;
	int c = 0;
	while (c < i)
	{
		while (text[temp] != '\n')
			temp++;
		temp++;
	}
	if (text[temp] == 'n')
		text[temp] = 'j';
	else if (text[temp] == 'j')
		text[temp] = 'n';
}

int main()
{
	FILE	*fp;
	int		i = 0;
	fp = fopen("src.txt", "r");
	long fsize = 10000;
	text = malloc(fsize + 1);
	checkList = malloc(700 * 4);
	while (i< 636)
	{
		fseek(fp, 0, SEEK_SET);
		fread(text, 1, fsize, fp);
		line = 0;
		cur = 0;
		acc = 0;
		free(checkList);
		checkList = malloc(700 * 4);
		changeline(i);
		while (line < 637)
		{
			if (!readLine(i))
				break;
		}
		i++;
	}
	fclose(fp);
	if (checkList[636] == 1)
		printf("win: %d", acc);
	printf("fail: %d\n", line);
}