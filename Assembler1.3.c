/*
 * asem1.3.c
 * Tushin Kirill
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FUNCTION.fun"

#define STR 10

void clear(char * arr);

#define DEF_CMD(p)\
		if(strcmp(arr,Mass[p].name) == 0){\
			fprintf(fout, "%d ", Mass[p].num);\
			if(Mass[p].arg){\
				fscanf(fin,"%d", &ar);\
				fprintf(fout, "%d ", ar);}}

int main()
{
	FILE *fin, *fout;
	int a = 0, i = 0, ar;
	char c;
	char arr[STR] = {};
	
	if (!(fin = fopen("test.asem", "r"))) 
	{ 
		printf ("can't open a file for read\n"); 
		return -1; 
	}
	//==================================================================
	while(1)
	{
		c = fgetc(fin);
		if(c == EOF)
			break;
		if(c == '\n')
			a++;
		if(c == ' ')
			a++;
	}
	fclose(fin);
	//==================================================================
	if ((fin = fopen("test.asem", "r")) == NULL) 
	{ 
		printf ("can't open a file for read\n"); 
		return -1; 
	}
	
	if ((fout = fopen("my.forcpu", "wb")) == NULL) 
	{ 
		printf ("can't open a file for writing\n"); 
		return -1; 
	}
	//==================================================================
	
	while(a)
	{
		i = 0;
		c = fgetc(fin);
		while(c != ' ' && c != '\n' && c != EOF)
		{
			arr[i] = c;
			i++;
			c = fgetc(fin);
		}
		for(i = 0; i < NumberFunction; i++)
			DEF_CMD(i);
		a--;
		clear(arr);
	}	
	return 0;
}

void clear(char * arr)
{
	int i = 0;
	for(i = 0; i < STR; i++)
	{
		arr[i] = '\0';
	}
}
