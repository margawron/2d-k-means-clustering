#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "SFML\Graphics.h"


int readArgs(int arg_count, char ** arg_value, char ** inputFile, char ** outputFile, unsigned int * iterations, unsigned int * numberOfFocals)
{
	if (arg_count == 1)
	{
		printf("Przyklad uzycia\n");
		printf(" -i [nazwa pliku wejsciowego] -o [nazwa pliku wyjsciowego] -c [ilosc iteracji po ktorej program ma przestac dzialac] -g [liczba grup danych]\n");
		return 1;
	}
	else if (arg_count == 9)
	{
		int arg_check = 0;
		for (int i = 0; i < arg_count; i++)
		{
			if (!strcmp("-i", arg_value[i]))		// plik we
			{
				*inputFile = strdup(*(arg_value + i + 1));
				arg_check = arg_check | 00001;
			}
			if (!strcmp("-o", arg_value[i]))		// plik wy
			{
				*outputFile = strdup(*(arg_value + i + 1));
				arg_check = arg_check | 00010;
			}
			if (!strcmp("-c", arg_value[i]))		// iloœæ maks iteracji
			{
				*iterations = atoi(arg_value[i + 1]);
				arg_check = arg_check | 00100;
			}
			if (!strcmp("-g", arg_value[i]))		// iloœæ grup
			{
				*numberOfFocals = atoi(arg_value[i + 1]);
				arg_check = arg_check | 01000;
			}
		}
		if (arg_check == 01111)
		{
			return 0;
		}
		else {
			printf("Niepoprawnie podano argumenty");
			return 1;
		}
	}
	printf("Nie prawidlowa ilosc argumentow");
	return 1;
}

int openFile(char * inputFile, sfImage ** handle)
{
	sfImage * inputHandle = sfImage_createFromFile(inputFile);
	*handle = inputHandle;
	if (*handle == NULL)
	{
		printf("Nie mozna otworzyæ pliku %s", inputFile);
		return 1;
	}
	return 0;
}

void closeFile(sfImage ** handle)
{
	sfImage_destroy(*handle);
	*handle = NULL;
}


int saveFile(char * outputFile,sfImage * handle)
{
	if (sfImage_saveToFile(handle, outputFile) == sfTrue) return 0;

	return 1;
}









