
#include "algorithm.h"
#include "io.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "SFML\Graphics.h"


void freePixels(point** dataPointer)
{
	if (*dataPointer != NULL)
	{
		free(*dataPointer);
		*dataPointer = NULL;
	}
}

unsigned int getAmountOfPoints(sfImage* handle)
{
	sfVector2u imageSize = sfImage_getSize(handle);

	long int amount = 0;

	for (unsigned int i = 0; i < imageSize.y; i++)
	{
		for (unsigned int j = 0; j < imageSize.x; j++)
		{
			sfColor checked = sfImage_getPixel(handle, j, i);
			if (sfBlack.r == checked.r && sfBlack.g == checked.g && sfBlack.b == checked.b)
				amount++;
		}
	}
	return amount;
}

int allocatePointMemory(unsigned int amount, point** dataPointer)
{
	*dataPointer = (point*)malloc(sizeof(point) * amount);
	if (*dataPointer != NULL) return 0;
	printf("Nie mozna zaalokowac pamieci! (PUNKTY)");
	return 1;
}

void loadPointsToMem(point** dataPointer, sfImage* handle)
{
	unsigned int count = 0;
	sfVector2u size = sfImage_getSize(handle);
	for (int i = 0; i < size.x; i++)
	{
		for (int j = 0; j < size.y; j++)
		{
			sfColor check = sfImage_getPixel(handle, i, j);
			if (sfBlack.r == check.r && sfBlack.g == check.g && sfBlack.b == check.b)
			{
				(*dataPointer + count)->x = i;
				(*dataPointer + count)->y = j;
				(*dataPointer + count)->affil = NULL;
				count++;
			}
		}
	}
}

int allocateFocalMemory(unsigned int amount, focal** dataPointer)
{
	(*dataPointer) = (focal*)malloc(sizeof(focal) * amount);

	if (*dataPointer != NULL) return 0;
	printf("Nie mozna zaalokowac pamieci! (OGNISKA/PUNKTY SKUPIENIA)");
	return 1;
}


void loadFocals(focal** dataFocals, point** dataPoints, unsigned int amountOfDots, unsigned int amountOfFocals)
{
	unsigned int randomDot = 0;
	for (int i = 0; i < amountOfFocals; i++)
	{
		unsigned int randomDot = rand() % amountOfDots;
		(*dataFocals + i)->x = (*dataPoints + randomDot)->x;
		(*dataFocals + i)->y = (*dataPoints + randomDot)->y;
		(*dataFocals + i)->color.r = (rand() % 255);
		(*dataFocals + i)->color.g = (rand() % 255);
		(*dataFocals + i)->color.b = (rand() % 255);
		(*dataFocals + i)->color.a = 255;
	}
}


void setFocals(focal* focalPoints, point** dataPointer, unsigned int amountOfPoints, unsigned int amountOfFocals,sfImage* handle, unsigned int maxIterations, short doInbetween)
{
	int* previousCoords = (int*)malloc(amountOfFocals * 2 * sizeof(int)); // tablica przechowywuj¹ca poprzednie koordynaty punktow skupienia
	long int iteration = 0;


	char filename[20];
	sprintf(filename, "%d.png",iteration);

	//przypisz 0 dla wartoœci poprzednich
	for (int i = 0; i < amountOfFocals; i++)
	{
		*(previousCoords + i) = (focalPoints + i)->x;
		*(previousCoords + amountOfFocals + i) = (focalPoints + i)->y;

	}

	for (int i = 0; i < amountOfPoints; i++)
	{
		(*dataPointer + i)->affil = focalPoints;
	}

	//0 wartoœci siê nie zmieni³y
	//1 wartoœci siê zmieni³y
	short hasChanged = 1;

	// __WHILE__
	//
	while (hasChanged)
	{

		iteration++;
		printf("Wykonuje %d na maksymalne %d iteracji\n", iteration, maxIterations);

		if (doInbetween)
			sprintf(filename, "%d.png" , iteration);

		hasChanged = 0;
		float distanceFromParent, distanceFromFocal;
		/*
			Ustawianie najkrótszej odleg³oœci dla ka¿dego punktu w tablicy wskazywanej przez	 point ** dataPointer
		*/
		for (int i = 0; i < amountOfPoints; i++)
		{
			distanceFromParent = sqrt(pow((*dataPointer + i)->x - (*dataPointer + i)->affil->x, 2) + pow((*dataPointer + i)->y - (*dataPointer + i)->affil->y, 2));

			for (int j = 0; j < amountOfFocals; j++)
			{
				distanceFromFocal = sqrt(pow((*dataPointer + i)->x - (focalPoints + j)->x, 2) + pow((*dataPointer + i)->y - (focalPoints + j)->y, 2));

				if (distanceFromFocal < distanceFromParent)
				{
					(*dataPointer + i)->affil = focalPoints + j;
				}
			}
		}
		/*
			Ustawianie najkrótszej odleg³oœci dla ka¿dego punktu w tablicy wskazywanej przez	 point ** dataPointer
		*/


		// Ustawienie nowych koordynatów punktów skupienia
		for (int i = 0; i < amountOfFocals; i++)
		{
			long long int x = 0, y = 0, count = 0;
			for (int j = 0; j < amountOfPoints; j++)
			{
				if ((*dataPointer + j)->affil == (focalPoints + i))
				{
					x = x + (*dataPointer + j)->x;
					y = y + (*dataPointer + j)->y;
					count++;
				}
			}
			if (count != 0)
			{
				(focalPoints + i)->x = x / count;
				(focalPoints + i)->y = y / count;
			}
		}
		//Sprawdzenie czy koordynaty punktów skupienia siê zmieni³y siê po miêdzy iteracjami
		for (int i = 0; i < amountOfFocals; i++)
		{


			int prev_x = *(previousCoords + i);
			int prev_y = *(previousCoords + amountOfFocals + i);
			int curr_x = (int)(focalPoints + i)->x;
			int curr_y = (int)(focalPoints + i)->y;
			if (!(prev_x == curr_x && prev_y == prev_y) && maxIterations > iteration)
			{
				hasChanged = 1;
			}
		}

		for (int i = 0; i < amountOfFocals; i++)
		{

			*(previousCoords + i) = (focalPoints + i)->x;
			*(previousCoords + amountOfFocals + i) = (focalPoints + i)->y;

		}
		if (doInbetween)
		{
			changeImage(*dataPointer, amountOfPoints, handle);
			saveFile(filename, handle);
		}
	}
	//
	free(previousCoords);
	// __WHILE__
}

void changeImage(point* points, unsigned int amountOfPoints,sfImage* handle)
{
	for (int i = 0; i < amountOfPoints; i++)
	{
		sfImage_setPixel(handle, (points + i)->x, (points + i)->y, (points + i)->affil->color);
	}
}

void freeFocals(focal** dataPointer)
{
	if (*dataPointer != NULL)
	{
		free(*dataPointer);
		*dataPointer = NULL;
	}
}


