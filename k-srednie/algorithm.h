#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#include "SFML\Graphics.h"




//
// Struktura focal
// struktura opisuj�ca punkt skupienia danych
//
typedef struct {
	float x, y;					// koordynaty punktu skupienia
	sfColor color;				// kolor przypisany do punktu skupienia danych
}focal;

//
// Struktura point
// struktura przechowywuje koordynaty punktu i przynale�no�� punktu na p�aszczy�nie
//
typedef struct {
	unsigned int x, y;	//koordynaty punktu z danymi
	focal * affil;		//wska�nik na element typu focal opisuj�cy punkt skupienia danych
}point;

//
// Funkcja getPoints
// funkcja zlicza czarne punkty na bitmapie i zwraca ich ilo��
// sfImage * handle - uchwyt do pliku z bitmapie
// return - zwraca liczb� czarnych punkt�w
//
unsigned int getAmountOfPoints(sfImage * handle);

//
// Funkcja allocatePointMemory
// funkcja alokuje pami�� dla danych typu point
// unsigned int amount - ilo�� pikseli dla kt�rych potrzebna jest pami��
// point ** dataPointer - wska�nik na pami�� kt�ra zostanie zaalokowana przez funkcj�
// return - funkcja zwraca 1 je�eli alokacja pami�ci si� uda�a, 0 je�eli alokacja si� nie uda�a
//
int allocatePointMemory(unsigned int amount, point ** dataPointer);

//
// Funkcja allocateFocalMemory
// funkcja alokuje pami�� dla danych typu point
// unsigned int amount - ilo�� pikseli dla kt�rych potrzebna jest pami��
// point ** dataPointer - wska�nik na pami�� kt�ra zostanie zaalokowana przez funkcj�
// return - funkcja zwraca 1 je�eli alokacja pami�ci si� uda�a, 0 je�eli alokacja si� nie uda�a
//
int allocateFocalMemory(unsigned int amount, focal ** dataPointer);

//
// Funkcja loadPointsToMem
// funkcja zapisuje punkty ze struktury sfImage do tablicy wskazanej przez dataPointer 
// point ** dataPointer - wska�nik na tablic� z punktami
// sfImage * handle - uchwyt do struktury przechowywuj�cej piksele
//
void loadPointsToMem(point ** dataPointer, sfImage * handle);

//
// Funkcja loadFocals
// funkcja ustawia podan�, losow� ilo�� punkt�w
// focal ** dataFocals - wska�nik na wska�nik na blok pami�ci do kt�rego nale�y za�adowa� punkty
// point ** dataPoints - wska�nik na wska�nik na block pami�ci zawier�cy punkty z kt�rego nale�y wylosowa� punkty skupienia
// unsigned int amountOfDots - ilo�� punkt�w w bloku pami�ci
// unsigned int amountOfFocals - ilo�� punkt�w skupienia w bloku pami�ci (ilo�� punkt�w skupienia do wylosowania)
//
void loadFocals(focal ** dataFocals, point ** dataPoints, unsigned int amountOfDots, unsigned int amountOfFocals);

//
// Funkcja setFocals
// funkcja ustala stacjonarne punkty skupienia (tk. takie kt�re po kolejnych iteracjach si� nie przemieszcz�) b�d� przerywa po okre�lonej liczbie iteracji
// focal * focalPoints - adres blok pami�ci z punktami skupienia
// point ** dataPointer - wska�nik na adres do bloku pami�ci kt�ry przechowuje czarne punkty (punkty danych) z bitmapy
// unsigned int amountOfPoints - ilo�� (wielko�� bloku pami�ci) punkt�w danych
// unsigned int amountOfFocals - ilo�� (wielko�� bloku pami�ci) punkt�w skupienia 
// sfImage * handle - uchwyt do danych wczytanych z bitmapy
// unsigned int iterations - maksymalna ilo�c iteracji jak� mo�e wykona� program po czym ma zako�czy� wyznaczanie punkt�w skupie�
// short doInbetween - prze��cznik decyduj�cy czy funkcja ma robi� zrzuty po�o�enia danych do bitmapy co iteracj�
//
void setFocals(focal * focalPoints, point ** dataPointer, unsigned int amountOfPoints, unsigned int amountOfFocals, sfImage * handle, unsigned int iterations, short doInbetween);

//
// Funkcja changeImage
// funkcja nanosi kolor na piksele z danymi na bitmapie
// point * points - adres bloku pami�ci przychowywuj�cego punkty danych
// sfImage * handle - uchwyt do danych wczytanch z bitmapy
// 
void changeImage(point * points, unsigned int amountOfPoints, sfImage * handle);



#endif // !_ALGORITHM_H_
